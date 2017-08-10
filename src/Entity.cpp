#include <Mojagame/Entity.h>

Entity::Entity( App* app ) : _app(app) {}

Component* Entity::find( std::string name ) {
    std::vector<Component*>::iterator it = std::find_if( _components.begin(), _components.end(), [name](Component* component) {
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
    return component;
}

void Entity::remove( std::string name ) {
    _components.erase(
        std::remove_if( _components.begin(), _components.end(), [name](Component* component) {
            if ( component->getName() == name ) {
                component->onRemoved();
                return true;
            }
            return false;
        }),
        _components.end()
    );
}

/**
 * Getters
 */

App* Entity::getApp() {
    return _app;
}