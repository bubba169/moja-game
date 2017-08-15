#ifndef MOJAGAME_NATIVE_RENDERER_H
#define MOJAGAME_NATIVE_RENDERER_H

#ifdef DESKTOP
    #include <GLFW/glfw3.h>
#endif

class RenderContext {

    public:
        void drawTriangles( const float* data, int length );
        
    protected:
        GLuint _program;
        GLuint _vertexBuffer;
        GLuint _indexBuffer;
        
};

#endif