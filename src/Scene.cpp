#include <Mojagame/Scene.h>

Scene::Scene( App* app ) : _app(app) {
    grapevine.listen( SystemMessage::Update, [](int message, void* data) {
        printf("Updating in lambda %d\n", message);
        return true;
    });
        //std::bind(&Scene::onUpdate, this, std::placeholders::_1, std::placeholders::_2));
}

bool Scene::onUpdate( int message, void* data ) {
    printf("Updating %d\n", message);
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