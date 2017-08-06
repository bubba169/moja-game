#include <Mojagame/Scene.h>

Scene::Scene( App* app ) : _app(app) {
}

void Scene::render( ) {
    grapevine.send( SystemMessage::PreRender );

    // TODO: Render the scene

    grapevine.send( SystemMessage::PostRender );
}