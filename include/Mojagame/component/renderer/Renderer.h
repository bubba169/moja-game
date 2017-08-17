#ifndef MOJAGAME_COMPONENT_RENDERER_H
#define MOJAGAME_COMPONENT_RENDERER_H

#include <Mojagame/Types.h>
#include <Mojagame/Component.h>

class Renderer : public Component {

    public:

        virtual ~Renderer() {};

        // Events
        virtual void onAdded( Entity* entity );
        virtual void onRemoved();

       virtual void render( RenderContext* context ) = 0;
       bool _onRenderMessage( int message, void* data );


    private:
        int _renderListenerId;
        
};

#endif