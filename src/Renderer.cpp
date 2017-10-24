#include <Mojagame/Renderer.h>

RenderContext::RenderContext() {
}

void RenderContext::init( ) {
    // Set up the basics
    glClearColor(0, 0, 0, 1);
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
}

void RenderContext::flush() {
}

void RenderContext::drawTriangles( std::vector<float>* vertices, std::vector<unsigned short>* indexes, int shaderId, int* textureIds, int numTextures )
{
    glBindBuffer( GL_ARRAY_BUFFER, _vertexBuffer );
    glBufferData( GL_ARRAY_BUFFER, vertices->size() * sizeof(GLfloat), (void*)&(vertices->front()), GL_STREAM_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _indexBuffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, indexes->size() * 2, (void*)&(indexes->front()), GL_STREAM_DRAW );

    Shader* shader = _shaders.at(shaderId);
    glUseProgram( shader->getProgram() );

    GLuint position = glGetAttribLocation( shader->getProgram(), "aPosition" );
    glEnableVertexAttribArray( position );
    glVertexAttribPointer( position, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);

    GLuint colour = glGetAttribLocation( shader->getProgram(), "aColour" );
    glEnableVertexAttribArray( colour );
    glVertexAttribPointer( position, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
    
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
    vsSrc += "attribute vec3 aPosition;";
    vsSrc += "attribute vec4 aColour;";
    vsSrc += "varying vec4 vColour;";
    vsSrc += "void main() {";
    vsSrc += "  gl_Position = vec4(aPosition, 0);";
    vsSrc += "  vColour = aColour;";
    vsSrc += "}";

    std::string fsSrc("");
    fsSrc += "varying vec4 vColour;";
    fsSrc += "void main() {";
    fsSrc += "  gl_FragColor = vColour;";
    fsSrc += "}";

    uploadShader(new Shader( vsSrc, fsSrc ));
}

/**
 * Shaders
 */

 Shader::Shader( std::string vertexSrc, std::string fragmentSrc ) :
_program(0),
_vertexSrc(vertexSrc),
_fragmentSrc(fragmentSrc) {}

GLuint Shader::_compileShader( const char* src, GLint length, GLenum type ) {
    GLuint shader( glCreateShader(type) );
    glShaderSource( shader, 1, &src, &length );
    glCompileShader( shader );

    GLint result;
    glGetShaderiv( shader, GL_COMPILE_STATUS, &result);

    if ( !result ) {
        GLchar info[250];
        GLint infoLength;
        glGetShaderInfoLog( shader, 250, &infoLength, info );
        printf( "%s\n", info );
        return 0;
    }

    return shader;
}

GLuint Shader::getProgram() {
    return _program;
}

bool Shader::upload() {
    GLuint vs = _compileShader( _vertexSrc.c_str(), _vertexSrc.length(), GL_VERTEX_SHADER );
    printf("Compiled vertex shader: %d\n", vs);

    GLuint fs = _compileShader( _fragmentSrc.c_str(), _fragmentSrc.length(), GL_FRAGMENT_SHADER );
    printf("Compiled fragment shader: %d\n", fs);

    _program = glCreateProgram();
    glAttachShader( _program, vs );
    glAttachShader( _program, fs );
    glLinkProgram( _program );

    GLint result;
    glGetProgramiv( _program, GL_LINK_STATUS, &result);

    if ( !result ) {
        GLchar info[250];
        GLint infoLength;
        glGetProgramInfoLog( _program, 250, &infoLength, info );
        printf( "%s\n", info );
        return false;
    }

    return true;

    printf("Compiled shader program: %d\n", _program);
}

