#ifndef MOJAGAME_SCENE_H
#define MOJAGAME_SCENE_H

#include <Mojagame/App.h>
#include <Mojagame/Grapevine.h>
#include <cstdio>

// Forward declaration so Entity can see Scene
class Scene;
class App;

class Entity {

    public:
        Scene* getScene();

    protected:
        Scene* _scene;

};

class Scene : public GrapevineListener {

    public:
        Scene( App* app );

        Entity* create();
        void destroy();

        void render();
        void update( double delta );

        Grapevine grapevine;
        bool onUpdate( int message, void* data );

    protected:
        std::vector<Entity*> _entities;
        App* _app;

};

#endif