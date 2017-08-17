#ifndef MOJAGAME_NATIVE_RENDERER_H
#define MOJAGAME_NATIVE_RENDERER_H

#ifdef DESKTOP
    #include <GLFW/glfw3.h>
#endif

#include <Mojagame/native/renderer/RenderContext.h>
#include <Mojagame/Types.h>
#include <string>

class GLShader {
    public:
        GLShader( std::string vertexSrc, std::string fragmentSrc );
        GLuint getProgram();
        GLuint upload();
    protected:
        std::string _vertexSrc;
        std::string _fragmentSrc;
        GLuint _program;

        GLuint _compileShader( const char* src, GLint length, GLuint type );
}

class GLRenderContext : public RenderContext {

    public:

        virtual void clear();

        virtual void init() = 0;
        virtual void resize( int width, int height ) = 0;

        // This is the basic call all others use.
        virtual void drawTriangle( const Vec2* vertices, Mat4 transform, Colour colour ) = 0;
        virtual void drawTriangle( const Vec2* vertices, Mat4 transform, unsigned int textureId, const Vec2* u ) = 0;
        
    protected:
        GLuint _vertexBuffer;
        GLuint _indexBuffer;

        GLShader* _colourShader;
        GLShader* _textureShader;

        void _initShaders();
        
};

#endif