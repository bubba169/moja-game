#pragma once

// Forward declare these because we have no definite definition at this point
// It all depends on the compiler settings and the platform

struct AppConfig {
    const char* title;
    int windowWidth = 1280;
    int windowHeight = 800;
    int stageWidth = 1280;
    int stageHeight = 800;
};

/**
 * App is a static class that grants access to the lower level functionality
 */

class Platform;
class Scene;

class App {

    public:
        static App* current();
        
        App( AppConfig* config );
        virtual ~App();
        int run(int argc, char* argv[]);
        void tick();

        virtual void init();
        virtual void update(double seconds);
        virtual void render();
        virtual void shutdown();

        virtual void resize(int width, int height, float pixelRatio);

        AppConfig* getConfig();
        Platform* getPlatform();
        Scene* getScene();

        std::string getPath(std::string);

    protected:
    
    private:
        static App* __current;
        unsigned long __lastTick;
        Platform* __platform;
        AppConfig* __config;
        Scene* __scene;
        std::string __appPath;
};