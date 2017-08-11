#ifndef COMPONENTS_QUAR_RENDERER_H
#define COMPONENTS_QUAR_RENDERER_H

#include <Mojagame/component/renderer/Renderer.h>

class QuadRenderer : public Renderer {

    public:
        virtual std::string getName();
        virtual void render( RenderContext* context );
};

#endif