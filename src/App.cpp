#include <Mojagame.h>

App::App( AppConfig* config ) : __config(config) {
    
    __platform = new Platform();
    __scene = new Scene();
    App::__current = this;
}

App::~App() {
    delete __platform;
    delete __scene;
}

App* App::__current;
App* App::current() {
    return __current;
}

/**
 * Platform interface
 */
int App::run(int argc, char* argv[]) 
{
    std::size_t pos = std::string(argv[0]).find_last_of('/');
    if (pos == std::string::npos) {
        __appPath = "";
    } else {
        __appPath = std::string(argv[0]).substr(0, pos);
    }

    printf("App path is %s\n", __appPath.c_str());
    
    // This is the final step to enter the game loop
    __lastTick = __platform->timeInMilliseconds();
    return __platform->run( this );
}

void App::tick() 
{
    unsigned long currentTime = __platform->timeInMilliseconds();
    double sinceLastTick = (currentTime - __lastTick) / 1000.0;
    __lastTick = currentTime;

    // Update the app
    update(sinceLastTick);

    // render
    render();
}

/**
 * Functions to override
 */
void App::init() {
    __scene->init(__config->stageWidth, __config->stageHeight);
}
void App::update( double seconds ) {}

void App::render() {
    __scene->render();
}

void App::shutdown() {}

/**
 * Functions that wouldn't normally be overridden
 */
void App::resize(int width, int height, float pixelRatio) {
    __scene->resize(width, height, pixelRatio);
}

/**
 * Getters
 */

Platform* App::getPlatform() {
    return __platform;
}

AppConfig* App::getConfig() {
    return __config;
}

Scene* App::getScene() {
     return __scene;
}

std::string App::getPath(std::string path) {
    if (path.at(0) != '/') {
        path = "/" + path;
    }

    return __appPath + path;
}