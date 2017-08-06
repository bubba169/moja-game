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
    _lastTick = pt::microsec_clock::universal_time();
    return platform->run( this );
}

void App::update() {

    pt::ptime currentTime = pt::microsec_clock::universal_time();
    double sinceLastTick = (currentTime - _lastTick).total_milliseconds() / 1000.0;

    grapevine.send( SystemMessage::Update, &sinceLastTick );
    
    scene->render();    

    _lastTick = currentTime;
    
}