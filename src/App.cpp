#include <Mojagame.h>

App::App( AppConfig* config ) : _config(config) {
    _grapevine = new Grapevine();
    _platform = new Platform();
    _scene = new Scene();
    App::_current = this;
}

App::~App() {
    delete _platform;
    delete _grapevine;
    delete _scene;
}

App* App::_current;
App* App::current() {
    return _current;
}

/**
 * Platform interface
 */
int App::run(int argc, char* argv[]) 
{
    std::size_t pos = std::string(argv[0]).find_last_of('/');
    if (pos == std::string::npos) {
        _appPath = "";
    } else {
        _appPath = std::string(argv[0]).substr(0, pos);
    }

    printf("App path is %s\n", _appPath.c_str());
    
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
    render();
}

/**
 * Functions to override
 */
void App::init() {
    _scene->init(_config->stageWidth, _config->stageHeight);
}
void App::update( double seconds ) {}

void App::render() {
    _scene->render();
}

void App::shutdown() {}

/**
 * Functions that wouldn't normally be overridden
 */
void App::resize(int width, int height, float pixelRatio) {
    _scene->resize(width, height, pixelRatio);

    Bundle size;
    size.set("width", width);
    size.set("height", height);
    _grapevine->send(SYSTEM_MESSAGE_RESIZE, &size);
}

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

Scene* App::getScene() {
     return _scene;
}

std::string App::getPath(std::string path) {
    if (path.at(0) != '/') {
        path = "/" + path;
    }

    return _appPath + path;
}