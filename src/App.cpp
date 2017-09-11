#include <Mojagame/App.h>
#include <Mojagame/native/Platform.h>
#include <Mojagame/Grapevine.h>
#include <Mojagame/Factory.h>
#include <Mojagame/Scene.h>

App::App( AppConfig* config, GameEngine* engine ) : _config(config), _engine(engine) {
    _factory = new Factory(this);
    _grapevine = new Grapevine();
    _platform = new Platform();
    _scene = new Scene(this);
}

App::~App() {
    delete _platform;
    delete _factory;
    delete _grapevine;
    delete _scene;
}

int App::run() 
{
    // Set up the other platforms here
    _engine->init( this );

    // This is the final step to enter the game loop
    _lastTick = _platform->timeInMilliseconds();

    return _platform->run( this );
}

void App::update() 
{
    unsigned long currentTime = _platform->timeInMilliseconds();
    double sinceLastTick = (currentTime - _lastTick) / 1000.0;

    _grapevine->send( SYSTEM_MESSAGE_UPDATE, &sinceLastTick );

    _lastTick = currentTime;
}

void App::render() 
{
    _grapevine->send( SYSTEM_MESSAGE_RENDER );
    _grapevine->send( SYSTEM_MESSAGE_POST_RENDER );
}

/**
 * Getters
 */

Factory* App::getFactory() {
    return _factory;
}

Platform* App::getPlatform() {
    return _platform;
}

Grapevine* App::getGrapevine() {
    return _grapevine;
}

AppConfig* App::getConfig() {
    return _config;
}

Scene* App::getScene() {
    return _scene;
}