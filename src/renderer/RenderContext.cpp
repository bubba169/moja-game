#include <Mojagame/Renderer.h>
#include <Mojagame/math/Matrix.h>

RenderContext::RenderContext() {
}

void RenderContext::init( ) {
    // Set up the basics
    glClearColor(0, 1, 0, 1);
    _initShaders();

    glGenBuffers( 1, &_vertexBuffer );
    glGenBuffers( 1, &_indexBuffer );

    printf("Buffers %i %i\n", _vertexBuffer, _indexBuffer);
}

void RenderContext::clear() {
    glClear( GL_COLOR_BUFFER_BIT );
}

void RenderContext::resize( int width, int height ) {
    glViewport( 0, 0, width, height );

    float sx = 1.0 / width; 
    float sy = 1.0 / -height;

    _projection.identity();
    _projection.set(1, 1, 2 * sx);
    _projection.set(2, 2, 2 * sy);
    _projection.set(4, 1, -1);
    _projection.set(4, 2, 1);
}

void RenderContext::flush() {
}

void RenderContext::drawTriangles( std::vector<float>* vertices, std::vector<unsigned short>* indexes, int shaderId, Mat3* transform, int* textureIds, int numTextures )
{
    glBindBuffer( GL_ARRAY_BUFFER, _vertexBuffer );
    glBufferData( GL_ARRAY_BUFFER, vertices->size() * sizeof(GLfloat), (void*)&(vertices->front()), GL_STREAM_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _indexBuffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, indexes->size() * 2, (void*)&(indexes->front()), GL_STREAM_DRAW );

    Shader* shader = _shaders.at(shaderId);
    glUseProgram( shader->getProgram() );

    GLuint uProjection = glGetUniformLocation( shader->getProgram(), "uProjection");
    glUniformMatrix4fv( uProjection, 1, false, _projection.getData() );

    GLuint uTransform = glGetUniformLocation( shader->getProgram(), "uTransform");
    glUniformMatrix3fv( uTransform, 1, true, transform->getData() );

    GLuint position = glGetAttribLocation( shader->getProgram(), "aPosition" );
    glEnableVertexAttribArray( position );
    glVertexAttribPointer( position, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);

    GLuint colour = glGetAttribLocation( shader->getProgram(), "aColour" );
    glEnableVertexAttribArray( colour );
    glVertexAttribPointer( colour, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

    glDrawElements( GL_TRIANGLES, indexes->size(), GL_UNSIGNED_SHORT, 0 );
    
    int error( glGetError() );
    if ( error ) {
        printf( "GLError: %d\n", error );
    }
}

int RenderContext::uploadShader( Shader* shader ) {
    shader->upload();
    _shaders.push_back(shader);
    return _shaders.size() - 1;
}

int RenderContext::uploadTexture( Texture* texture ) {
    _textures.push_back(texture);
    return _textures.size() - 1;
}

void RenderContext::_initShaders() {

    // Build the colour shader;
    std::string vsSrc("");
    vsSrc += "attribute vec2 aPosition;";
    vsSrc += "attribute vec4 aColour;";
    vsSrc += "varying vec4 vColour;";
    vsSrc += "uniform mat4 uProjection;";
    vsSrc += "uniform mat3 uTransform;";
    vsSrc += "void main() {";
    vsSrc += "  gl_Position = uProjection * vec4(uTransform * vec3(aPosition, 1), 1);";
    vsSrc += "  vColour = aColour;";
    vsSrc += "}";

    std::string fsSrc("");
    fsSrc += "varying vec4 vColour;";
    fsSrc += "void main() {";
    fsSrc += "  gl_FragColor = vColour;";
    fsSrc += "}";

    uploadShader(new Shader( vsSrc, fsSrc ));
}