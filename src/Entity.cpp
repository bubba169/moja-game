#include <Mojagame/Entity.h>

Entity::Entity( App* app ) : _app(app) {}

Component* Entity::find( std::string name ) {
    std::vector<Component*>::iterator it = std::find_if( _components.begin(), _components.end(), [name](Component* component) {
        if ( !component->getIsRemoved() && component->getName() == name ) {
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
    return component;
}

Component* Entity::remove( std::string name ) {

    std::vector<Component*>::iterator it = std::find_if( _components.begin(), _components.end(), [name](Component* component) {
        if ( !component->getIsRemoved() && component->getName() == name ) {
            component->onRemoved();
            return true;
        }
        return false;
    });

    Component* removed = *it;

    if ( it != _components.end() ) {
        _components.erase( it );
    };

    return removed;
}

/**
 * Getters
 */

App* Entity::getApp() {
    return _app;
}