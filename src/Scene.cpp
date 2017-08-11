#include <Mojagame/Scene.h>

Scene::Scene( App* app ) : _app(app) {
    GrapevineListener listener = std::bind(&Scene::onMessage, this, std::placeholders::_1, std::placeholders::_2);
    _addedListenerId = app->getGrapevine()->listen( SystemMessage::RendererAdded, listener );
}

bool Scene::onMessage( int message, void* data ) {
    switch( message ) {
        case SystemMessage::RendererAdded:
            _onRendererAdded( (Entity*) data );
    }

    return true;
}

void Scene::_onRendererAdded( Entity* entity ) {
    // TODO:: Add the renderer to the list in the correct position
}