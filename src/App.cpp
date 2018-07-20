#include <Mojagame.h>

App::App( AppConfig* config ) : __config(config) {
    
    __platform = new Platform();
    __scene = new Scene();
    __inputMap = new InputMap();
    App::__current = this;
}

App::~App() {
    delete __platform;
    delete __scene;
    delete __inputMap;
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

InputMap* App::getInputMap() {
    return __inputMap;
}

std::string App::getPath(std::string path) {
    if (path.at(0) != '/') {
        path = "/" + path;
    }

    return __appPath + path;
}

void App::onKeyDown(int key, int mods) {
    __inputMap->onKeyDown(key);
    KeyEvent event(EventType::KeyDown, key, mods);
    __scene->getEventDispatcher()->dispatch(&event);
}

void App::onKeyUp(int key, int mods) {
    __inputMap->onKeyUp(key);
    KeyEvent event(EventType::KeyUp, key, mods);
    __scene->getEventDispatcher()->dispatch(&event);
}

void App::onPointerUp(int pointerId, int x, int y, int button) {
    //__inputMap->onPointerUp(key);
    PointerEvent event(EventType::PointerUp, pointerId, x, y, button);
    __scene->getEventDispatcher()->dispatch(&event);
}

void App::onPointerDown(int pointerId, int x, int y, int button) {
    //__inputMap->onPointerUp(key);
    PointerEvent event(EventType::PointerDown, pointerId, x, y, button);
    __scene->getEventDispatcher()->dispatch(&event);
}

void App::onPointerMove(int pointerId, int x, int y) {
    //__inputMap->onPointerUp(key);
    PointerEvent event(EventType::PointerMove, pointerId, x, y);
    __scene->getEventDispatcher()->dispatch(&event);
}

