#ifndef MOJAGAME_NATIVE_RENDERER_H
#define MOJAGAME_NATIVE_RENDERER_H

#ifdef DESKTOP
    #include <GLFW/glfw3.h>
#endif

#include <Mojagame/Types.h>

class RenderContext {

    public:
        void drawQuad( Mat4 transform, Colour colour );
        void drawTriangle( const float* data, int length );
        
    protected:
        GLuint _program;
        GLuint _vertexBuffer;
        GLuint _indexBuffer;
        
};

#endif