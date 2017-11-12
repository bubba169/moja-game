// #include <Mojagame/Scene.h>
// #include <Mojagame/App.h>
// #include <Mojagame/component/Transform.h>
// #include <Mojagame/Grapevine.h>
// #include <Mojagame/Renderer.h>

// Scene::Scene( App* app ) : _app(app) {
//     _rootTransform = new Transform();

//     GrapevineListener listener = std::bind(&Scene::onMessage, this, std::placeholders::_1, std::placeholders::_2);
//     _renderListenerId = app->getGrapevine()->listen( SYSTEM_MESSAGE_RENDER, listener );
// }

// void Scene::initRenderer() {
//     _renderContext = new RenderContext();
//     _renderContext->init();
// }

// Scene::~Scene() {
//     delete _rootTransform;
// }

// bool Scene::onMessage( int message, void* data ) {
//      switch( message ) {
//         case SYSTEM_MESSAGE_RENDER:
//             _renderContext->clear();
//             _renderObject( _rootTransform );
//     }

//     return true;
// }

// void Scene::_renderObject( Transform* transform ) {
    
//     Entity* entity = transform->getEntity();
//     if ( entity != NULL ) {
//         entity->getGrapevine()->send( SYSTEM_MESSAGE_RENDER, (void*)_renderContext );
//     }
    
//     std::for_each( transform->begin(), transform->end(), [this] ( Transform* child ) {
//         _renderObject( child );
//     });

//     if ( entity != NULL ) {
//         entity->getGrapevine()->send( SYSTEM_MESSAGE_POST_RENDER );
//     }
// }

// Transform* Scene::getRoot() {
//     return _rootTransform;
// }