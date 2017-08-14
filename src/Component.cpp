#include <Mojagame/Component.h>
#include <Mojagame/Entity.h>
#include <Mojagame/App.h>

Component::Component() : _entity(NULL) {}

void Component::onAdded( Entity* entity ) {
    _entity = entity;
}

void Component::onRemoved() {
    _entity = NULL;
}

/**
 * Getters
 */

App* Component::getApp() {
    if (_entity != NULL) {
        return _entity->getApp();
    } 
    return NULL;
}

Entity* Component::getEntity() {
    return _entity;
}
