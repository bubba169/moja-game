#ifndef MOJAGAME_NATIVE_RENDERER_RENDER_CONTEXT_H
#define MOJAGAME_NATIVE_RENDERER_RENDER_CONTEXT_H

#include <Mojagame/Types.h>
#include <Mojagame/util/Colour.h>

class RenderContext {

    public:

        RenderContext() {};
        virtual ~RenderContext() {};

        virtual void clear() = 0;

        virtual void init() = 0;
        virtual void resize( int width, int height ) = 0;

        // Flush any existing draw calls if using batch drawing
        virtual void flush() {};

        // This is the basic call all others use.
        virtual void drawTriangles( std::vector<float>* vertices, std::vector<short>* indexes, int flags ) = 0;

    protected:
        
};

#endif