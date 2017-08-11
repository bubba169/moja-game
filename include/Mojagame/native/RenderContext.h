#ifndef MOJAGAME_NATIVE_RENDERER_H
#define MOJAGAME_NATIVE_RENDERER_H

class RenderContext {

    public:
        void drawTriangles( const float* data, int length );
        
    protected:
        GLuint _program;
        GLuint _vertexBuffer;
        GLuint _indexBuffer;
        
};

#endif