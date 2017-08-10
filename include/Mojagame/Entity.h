#ifndef MOJAGAME_SCENE_H
#define MOJAGAME_SCENE_H

#include <Mojagame/App.h>
#include <Mojagame/Grapevine.h>
#include <Mojagame/Component.h>
#include <algorithm>
#include <vector>

// Forward declaration so Entity can see Scene
class App;
class Component;

class Entity {

    public:
        Entity( App* app );
        //Transform* getTransform();
        Grapevine* getGrapevine();

        // Components
        Component* find( std::string name );
        Component* add( Component* );
        Component* remove( std::string name );

        // Getters
        App* getApp();

    protected:
        App* _app;
        //Transform _transform;
        Grapevine _grapevine;
        std::vector<Component*> _components;
};

#endif