#ifndef MOJAWORKS_APP_H
#define MOJAWORKS_APP_H

// Forward declare these because we have no definite definition at this point
// It all depends on the compiler settings and the platform

#include <Mojagame/Types.h>

struct AppConfig {
    const char* title;
    int windowWidth = 1280;
    int windowHeight = 800;
    int stageWidth = 1280;
    int stageHeight = 800;
};

/**
 * Game engine is a user defined class that has access to the app
 * This can construct the scene and provide additional systems and logic.
 */
class GameEngine {
    public:
        virtual void init(App* app) = 0;
};

/**
 * App is a static class that grants access to the lower level functionality
 */

class App {

    public:
        static App* current();
        
        App( AppConfig* config );
        virtual ~App();
        int run();
        void tick();

        virtual void init();
        virtual void update(double seconds);
        virtual void render();
        virtual void shutdown();

        virtual void resize(int width, int height, float pixelRatio);

        AppConfig* getConfig();
        Grapevine* getGrapevine();
        Platform* getPlatform();
        RenderContext* getRenderContext();
        Scene* getScene();

    protected:
        
        

    private:
        static App* _current;
        unsigned long _lastTick;
        Platform* _platform;
        AppConfig* _config;
        Grapevine* _grapevine;
        RenderContext* _renderContext;
        Scene* _scene;
};

#endif