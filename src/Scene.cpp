#include <Mojagame/Scene.h>

Scene::Scene( App* app ) : _app(app) {}

void Scene::update( double delta ) {
    Event updateEvent( EventType::Update, this, &delta );
    dispatch( &updateEvent );
}

void Scene::render( ) {

    Event preRenderEvent( EventType::PreRender, this );
    dispatch( &preRenderEvent );

    // Render the scene

    Event postRenderEvent( EventType::PostRender, this );
    dispatch( &postRenderEvent );

}