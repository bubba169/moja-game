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
    grapevine.send( SystemMessage::Update, &delta );
}

void Scene::render( ) {
    grapevine.send( SystemMessage::PreRender );

    // TODO: Render the scene

    grapevine.send( SystemMessage::PostRender );

}