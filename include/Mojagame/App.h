#ifndef MOJAWORKS_APP_H
#define MOJAWORKS_APP_H

// Forward declare these because we have no definite definition at this point
// It all depends on the compiler settings and the platform

#include <Mojagame/Types.h>

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
        
        App( AppConfig* config, GameEngine* engine );
        ~App();

        int run();
        void init();
        void update();
        void render();

        AppConfig* getConfig();
        Grapevine* getGrapevine();
        Factory* getFactory();
        Platform* getPlatform();
        Scene* getScene();

    protected:
        unsigned long _lastTick;

        GameEngine* _engine;
        Platform* _platform;
        AppConfig* _config;
        Grapevine* _grapevine;
        Factory* _factory;
        Scene* _scene;
};

#endif