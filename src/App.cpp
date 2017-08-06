#include <Mojagame/App.h>

App::App( AppConfig* config, GameEngine* engine ) : config(config), engine(engine) {}

App::~App() {
    delete platform;
    delete scene;
}

int App::run() {

    // Set up the other platforms here
    platform = new Platform();

    // Build the scene
    scene = new Scene( this );

    engine->init( this );

    // This is the final step to enter the game loop
    _lastTick = platform->timeInMilliseconds();
    return platform->run( this );
}

void App::update() {

    unsigned long currentTime = platform->timeInMilliseconds();
    double sinceLastTick = (currentTime - _lastTick) / 1000.0;

    grapevine.send( SystemMessage::Update, &sinceLastTick );

    scene->render();    

    _lastTick = currentTime;
    
}