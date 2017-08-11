#include <Mojagame/Component.h>

Component::Component() : _isRemoved(false), _entity(NULL) {}

void Component::onAdded( Entity* entity ) {
    _entity = entity;
}

void Component::onRemoved() {
    _entity = NULL;
}

/**
 * Getters
 */

bool Component::getIsRemoved() {
    return _isRemoved;
}

App* Component::getApp() {
    if (_entity != NULL) {
        return _entity->getApp();
    } 
    return NULL;
}

Entity* Component::getEntity() {
    return _entity;
}
