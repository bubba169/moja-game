#ifndef MOJAGAME_SHADER_H
#define MOJAGAME_SHADER_H

typedef std::vector<std::pair<std::string, int>> AttributeList;

class Shader {
    public:
        Shader( std::string vertexSrc, std::string fragmentSrc, int vertexSize, AttributeList attributes );
        AttributeList* getAttributes();
        int getVertexSize();
        GLuint getProgram();
        bool upload();
    protected:
        std::string _vertexSrc;
        std::string _fragmentSrc;
        AttributeList _attributes;
        GLuint _program;
        int _vertexSize;

        GLuint _compileShader( const char* src, GLint length, GLuint type );
};

#endif