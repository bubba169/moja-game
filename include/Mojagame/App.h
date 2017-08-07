#ifndef MOJAWORKS_APP_H
#define MOJAWORKS_APP_H


#ifdef DESKTOP
    #include <Mojagame/native/platform/GLFWPlatform.h>
#endif

#include <Mojagame/Scene.h>
#include <Mojagame/Grapevine.h>

//#include <boost/date_time/posix_time/posix_time.hpp>
//namespace pt = boost::posix_time;

// Forward declare these because we have no definite definition at this point
// It all depends on the compiler settings and the platform
class Platform;
class Scene;
class GameEngine;
class App;

struct AppConfig {
    const char* title;
    int windowWidth;
    int windowHeight;
};

/**
 * Game engine is a user defined class that has access to the app
 * This can construct the scene and provide additional systems and logic.
 */
class GameEngine {
    public:
        virtual void init(App* app) = 0;
};

class App {

    public:
        //InputSystem input;
        //Renderer renderer;
        //Network network;
        //AssetLoader assets;
        GameEngine* engine;
        Platform* platform;
        Scene* scene;
        AppConfig* config;
        Grapevine grapevine;

        App( AppConfig* config, GameEngine* engine );
        ~App();

        int run();
        void update();
        void render();

    protected:
        unsigned long _lastTick;
};

#endif