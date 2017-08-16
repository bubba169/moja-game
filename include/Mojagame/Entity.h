#ifndef MOJAGAME_ENTITY_H
#define MOJAGAME_ENTITY_H

#include <Mojagame/Types.h>

#include <algorithm>
#include <list>

class Entity {

    public:
         Entity( App* app );
        ~Entity();
        Entity* destroyAll();
        
        //Transform* getTransform();
        Grapevine* getGrapevine();

        // Components
        Component* find( std::string name );
        Component* add( Component* component );
        Component* remove( std::string name );

        Transform* getTransform();

        // Getters
        App* getApp();

    protected:
        App* _app;
        //Transform _transform;
        Grapevine* _grapevine;
        std::list<Component*> _components;
};

#endif