#include <Mojagame/App.h>

App::App( AppConfig* config, GameEngine* engine ) : config(config), engine(engine) {}

App::~App() {
    delete platform;
}

int App::run() 
{
    // Set up the other platforms here
    platform = new Platform();

    engine->init( this );

    // This is the final step to enter the game loop
    _lastTick = platform->timeInMilliseconds();

    return platform->run( this );
}

void App::update() 
{
    unsigned long currentTime = platform->timeInMilliseconds();
    double sinceLastTick = (currentTime - _lastTick) / 1000.0;

    grapevine.send( SystemMessage::Update, &sinceLastTick );

    _lastTick = currentTime;
}

void App::render() 
{
    grapevine.send( SystemMessage::Render );
    grapevine.send( SystemMessage::PostRender );
}