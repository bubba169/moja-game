#ifndef MOJAGAME_NATIVE_RENDERER_H
#define MOJAGAME_NATIVE_RENDERER_H

#ifdef MG_DESKTOP
    #include <GLFW/glfw3.h>
#endif

#include <Mojagame/native/renderer/RenderContext.h>
#include <Mojagame/Types.h>
#include <Mojagame/util/Colour.h>
#include <string>

class GLShader {
    public:
        GLShader( std::string vertexSrc, std::string fragmentSrc );
        GLuint getProgram();
        bool upload();
    protected:
        std::string _vertexSrc;
        std::string _fragmentSrc;
        GLuint _program;

        GLuint _compileShader( const char* src, GLint length, GLuint type );
};

class GLTexture {
    // GL texture stuff
};

class GLRenderContext : public RenderContext {

    public:
        GLRenderContext();
        void clear();

        void init();
        void resize( int width, int height );

        // This is the basic call all others use.
        void drawTriangles( std::vector<float>* vertices, std::vector<unsigned short>* indexes, int flags );
        
    protected:
        GLuint _vertexBuffer;
        GLuint _indexBuffer;

        GLShader* _colourShader;
        GLShader* _textureShader;

        void _initShaders();
        void _draw( std::vector<float>* vertices, std::vector<unsigned short>* indexes, GLShader* shader, GLTexture* texture );
};

#endif