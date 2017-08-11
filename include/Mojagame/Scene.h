#ifndef MOJAGAME_SCENE_H
#define MOJAGAME_SCENE_H

#include <Mojagame/App.h>
#include <Mojagame/Entity.h>

/**
 * Builds a list of entities as it receives RendererAdded events. Entities are placed in the list depending on their current parent
 * Calls a Render event on every entity in turn which can be picked up by a RendererComponent or ignored.
 */

class Scene {

    public:
        Scene( App* app );
        virtual ~Scene() {};
        bool onMessage( int message, void* data );

    protected:
        std::vector<Entity*> _renderList;
        App* _app;

        int _addedListenerId;

        void _onRendererAdded( Entity* entity );
};

#endif