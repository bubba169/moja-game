#include <Mojagame/Entity.h>
#include <Mojagame/Component.h>
#include <Mojagame/Grapevine.h>
#include <Mojagame/component/Transform.h>
#include <Mojagame/App.h>

Entity::Entity( App* app ) : _app(app) {
    _grapevine = new Grapevine();
}

Entity::~Entity() {
    delete _grapevine;

    // If any components are still attached, free them.
    std::for_each( _components.begin(), _components.end(), [] (Component* component) {
        component->onRemoved();
        delete component;
    });
    _components.empty();
}

/**
 * Destroys the entity including all of the children and any components attached to them
 */
Entity* Entity::destroyAll() {
    Transform* transform = getTransform();
    std::for_each( transform->begin(), transform->end(), []( Transform* child ) {
        delete child->getEntity()->destroyAll();
    });
    return this;
}

Component* Entity::find( std::string name ) {
    std::list<Component*>::iterator it = std::find_if( _components.begin(), _components.end(), [name](Component* component) {
        if ( component->getName() == name ) {
            return true;
        }
        return false;
    });

    if ( it != _components.end() ) {
        return *it;
    }

    return NULL;
}

Component* Entity::add( Component* component ) {
    _components.push_back( component );
    component->onAdded( this );
    return component;
}

Component* Entity::remove( std::string name ) {

    std::list<Component*>::iterator it = std::find_if( _components.begin(), _components.end(), [name](Component* component) {
        if ( component->getName() == name ) {
            component->onRemoved();
            return true;
        }
        return false;
    });

    if ( it != _components.end() ) {
        Component* removed = *it;
        _components.erase( it );
        return removed;
    };

    return NULL;

    
}

/**
 * Getters
 */

App* Entity::getApp() {
    return _app;
}

Grapevine* Entity::getGrapevine() {
    return _grapevine;
}

Transform* Entity::getTransform() {
    return (Transform*)find("Transform");
}