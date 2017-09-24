#include <Mojagame/native/renderer/GLRenderContext.h>

GLRenderContext::GLRenderContext() {
    
}

void GLRenderContext::init( ) {
    // Set up the basics
    glClearColor(0, 0, 0, 1);
    _initShaders();

    glGenBuffers( 1, &_vertexBuffer );
    glGenBuffers( 1, &_indexBuffer );

    /*float near(1), far(5000), fov(120), top(tan(fov*0.5)*near), right(top), left(-right), bottom(-top);
    float camElements[] = {
        (2*near)/(right-left), 0, (right+left)/(right-left), 0,
        0, (2*near)/(top-bottom), (top+bottom)/(top-bottom), 0,
        0, 0, -(far+near)/(far-near), (-2*far*near)/(far-near),
        0, 0, -1, 0
    };
    _cameraProjection.copyFrom( camElements );
    _cameraPosition.translate( 0, 0, 10)->inverse();

    _cameraPosition.print();*/
}

void GLRenderContext::resize( int width, int height ) {
    glViewport( 0, 0, width, height );
}

void GLRenderContext::_initShaders() {

    // Build the colour shader;
    std::string vsSrc("");
    vsSrc += "attribute vec3 aPosition;";
    vsSrc += "attribute vec4 aColour;";
    vsSrc += "varying vec4 vColour;";
    vsSrc += "void main() {";
    vsSrc += "  gl_Position = vec4(aPosition, 0);";
    vsSrc += "}";

    std::string fsSrc("");
    fsSrc += "varying vec4 vColour;";
    fsSrc += "void main() {";
    fsSrc += "  gl_FragColor = vColour;";
    fsSrc += "}";

    _colourShader = new GLShader( vsSrc, fsSrc );
}

void GLRenderContext::clear() {
    glClear( GL_COLOR_BUFFER_BIT );
}

void GLRenderContext::_draw( std::vector<float>* vertices, std::vector<unsigned short>* indexes, GLShader* shader, GLTexture* texture )
{
    glBindBuffer( GL_ARRAY_BUFFER, _vertexBuffer );
    glBufferData( GL_ARRAY_BUFFER, vertices->size() * 4, (void*)&vertices->front(), GL_STREAM_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _indexBuffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, indexes->size() * 2, (void*)&(indexes->front()), GL_STREAM_DRAW );

    glUseProgram( shader->getProgram() );

    GLuint position = glGetAttribLocation( shader->getProgram(), "aPosition" );
    glEnableVertexAttribArray( position );
    glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 17*4, 0);

    glDrawElements( GL_TRIANGLES, indexes->size(), GL_UNSIGNED_SHORT, 0 );

    int error( glGetError() );
    if ( error ) {
        printf( "GLError: %d\n", error );
    }

}

void GLRenderContext::drawTriangles( std::vector<float>* vertices, std::vector<unsigned short>* indexes, int flags )
{
    // batch or draw. Just draw for now
    //_draw( vertices, indexes, flags );
}

/**
 * Shaders
 */

 GLShader::GLShader( std::string vertexSrc, std::string fragmentSrc ) :
_program(0),
_vertexSrc(vertexSrc),
_fragmentSrc(fragmentSrc) {}

GLuint GLShader::_compileShader( const char* src, GLint length, GLenum type ) {
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

GLuint GLShader::getProgram() {
    return _program;
}

bool GLShader::upload() {
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

