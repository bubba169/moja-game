#ifndef MOJAGAME_SCENE_H
#define MOJAGAME_SCENE_H

#include <list>

/**
 * Builds a list of entities as it receives RendererAdded events. Entities are placed in the list depending on their current parent
 * Calls a Render event on every entity in turn which can be picked up by a RendererComponent or ignored.
 */

class Entity;
class Transform;
class App;

class Scene {

    public:
        Scene( App* app );
        virtual ~Scene();

        bool onMessage( int message, void* data );

        Transform* getRoot();

    protected:
        Transform* _rootTransform;
        App* _app;

        int _renderListenerId;
        void _renderObject( Transform* transform );
};

#endif