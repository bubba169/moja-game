#ifndef COMPONENTS_QUAR_RENDERER_H
#define COMPONENTS_QUAR_RENDERER_H

#include <Mojagame/Component.h>

class QuadRenderer : public Component {

    public:
        virtual std::string getName();

         // Events
        virtual void onAdded( Entity* entity );
        virtual void onRemoved();

        void render( RenderContext* context );

};

#endif