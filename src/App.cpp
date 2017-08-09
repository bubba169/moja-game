#include <Mojagame/App.h>

App::App( AppConfig* config, GameEngine* engine ) : _config(config), _engine(engine) {
    _factory = new Factory(this);
    _grapevine = new Grapevine();
    _platform = new Platform();
}

App::~App() {
    delete _platform;
    delete _factory;
    delete _grapevine;
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

    _grapevine->send( SystemMessage::Update, &sinceLastTick );

    _lastTick = currentTime;
}

void App::render() 
{
    _grapevine->send( SystemMessage::Render );
    _grapevine->send( SystemMessage::PostRender );
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