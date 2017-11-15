#include <Mojagame/App.h>
#include <Mojagame/native/Platform.h>
#include <Mojagame/Grapevine.h>
#include <Mojagame/Renderer.h>
//#include <Mojagame/Scene.h>

App::App( AppConfig* config ) : _config(config) {
    _grapevine = new Grapevine();
    _platform = new Platform();
    _renderContext = new RenderContext();
    //_scene = new Scene();
    App::_current = this;
}

App::~App() {
    delete _platform;
    delete _grapevine;
    delete _renderContext;
   // delete _scene;
}

App* App::_current;
App* App::current() {
    return _current;
}

/**
 * Platform interface
 */
int App::run() 
{
    // This is the final step to enter the game loop
    _lastTick = _platform->timeInMilliseconds();
    return _platform->run( this );
}

void App::tick() 
{
    unsigned long currentTime = _platform->timeInMilliseconds();
    double sinceLastTick = (currentTime - _lastTick) / 1000.0;
    _lastTick = currentTime;

    // Update the app
    update(sinceLastTick);

    // render
    render(_renderContext);
}

/**
 * Functions to override
 */
void App::init() {
    _renderContext->init();
}
void App::update( double seconds ) {}

void App::render( RenderContext* context ) {
    context->clear();
}

void App::shutdown() {}

/**
 * Getters
 */

Platform* App::getPlatform() {
    return _platform;
}

Grapevine* App::getGrapevine() {
    return _grapevine;
}

AppConfig* App::getConfig() {
    return _config;
}

// Scene* App::getScene() {
//     return _scene;
// }