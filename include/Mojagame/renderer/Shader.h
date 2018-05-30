#ifndef MOJAGAME_SHADER_H
#define MOJAGAME_SHADER_H

class Shader {
    public:
        Shader( std::string vertexSrc, std::string fragmentSrc );
        GLuint getProgram();
        bool upload();
    protected:
        std::string _vertexSrc;
        std::string _fragmentSrc;
        GLuint _program;

        GLuint _compileShader( const char* src, GLint length, GLuint type );
};

#endif