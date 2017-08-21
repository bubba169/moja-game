#ifndef MOJAGAME_NATIVE_RENDERER_RENDER_CONTEXT_H
#define MOJAGAME_NATIVE_RENDERER_RENDER_CONTEXT_H

#include <Mojagame/Types.h>
#include <Mojagame/util/Colour.h>

class RenderContext {

    public:

        RenderContext() {};
        virtual ~RenderContext() {};

        virtual void clear();

        virtual void init() = 0;
        virtual void resize( int width, int height ) = 0;

        // Draw filled quad or a quad with a texture.
        void drawQuad( Mat4 transform, Colour colour );
        void drawQuad( Mat4 transform, unsigned int textureId, const Vec2* uv );

        // This is the basic call all others use.
        virtual void drawTriangle( const Vec2* vertices, Mat4* transform, Colour colour ) = 0;
        virtual void drawTriangle( const Vec2* vertices, Mat4* transform, unsigned int textureId, const Vec2* u ) = 0;

    protected:
        
};

#endif