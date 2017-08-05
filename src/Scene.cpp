#include <Mojagame/Scene.h>

Scene::Scene( App* app ) : _app(app) {
    grapevine.listen( this, &GrapevineListener::onUpdate, SystemMessage::Update );
}

bool Scene::onUpdate( int message, void* data ) {
    prinft("Updating %d", message);
}



void Scene::update( double delta ) {
    //Event updateEvent( EventType::Update, this, &delta );
    //dispatch( &updateEvent );
    grapevine.send( SystemMessage::Update, &delta );
}

void Scene::render( ) {

    //Event preRenderEvent( EventType::PreRender, this );
    //dispatch( &preRenderEvent );
    grapevine.send( SystemMessage::PreRender );

    // Render the scene

    //Event postRenderEvent( EventType::PostRender, this );
    //dispatch( &postRenderEvent );
    grapevine.send( SystemMessage::PostRender );

}