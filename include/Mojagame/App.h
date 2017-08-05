#ifndef MOJAWORKS_APP_H
#define MOJAWORKS_APP_H


#ifdef DESKTOP
    #include <Mojagame/native/platform/GLFWPlatform.h>
#endif

#include <Mojagame/Scene.h>

#include <boost/date_time/posix_time/posix_time.hpp>
namespace pt = boost::posix_time;

// Forward declare these because we have no definite definition at this point
// It all depends on the compiler settings and the platform
class Platform;
class Scene;

struct AppConfig {
    const char* title;
    int windowWidth;
    int windowHeight;
};

class App {

    public:
        //InputSystem input;
        //Renderer renderer;
        //Network network;
        //AssetLoader assets;
        Platform* platform;
        Scene* scene;
        AppConfig* config;

        App( AppConfig* config );
        ~App();

        int run();
        void update();

    protected:
        pt::ptime _lastTick;
};

#endif