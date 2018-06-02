#include <Mojagame.h>

Shader::Shader( std::string vertexSrc, std::string fragmentSrc, int vertexSize, AttributeList attributes ) :
_program(0),
_vertexSrc(vertexSrc),
_fragmentSrc(fragmentSrc),
_attributes(attributes),
_vertexSize(vertexSize) {}

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
    GLuint fs = _compileShader( _fragmentSrc.c_str(), _fragmentSrc.length(), GL_FRAGMENT_SHADER );

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
}

AttributeList* Shader::getAttributes() {
    return &_attributes;
}

int Shader::getVertexSize() {
    return _vertexSize;
}
