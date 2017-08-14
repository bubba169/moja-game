#include <Mojagame/Scene.h>
#include <Mojagame/App.h>
#include <Mojagame/Entity.h>
#include <Mojagame/component/Transform.h>

Scene::Scene( App* app ) : _app(app) {
    _rootTransform = new Transform();

    GrapevineListener listener = std::bind(&Scene::onMessage, this, std::placeholders::_1, std::placeholders::_2);
    _renderListenerId = app->getGrapevine()->listen( SystemMessage::Render, listener );
}

Scene::~Scene() {
    delete _rootTransform;
}

bool Scene::onMessage( int message, void* data ) {
     switch( message ) {
        case SystemMessage::Render:
            _renderObject( _rootTransform );
    }

    return true;
}

void Scene::_renderObject( Transform* transform ) {
    
    Entity* entity = transform->getEntity();
    if ( entity != NULL ) {
        entity->getGrapevine()->send( SystemMessage::Render );
    }

    std::for_each( transform->begin(), transform->end(), [this] ( Transform* child ) {
        _renderObject( child );
    });
}