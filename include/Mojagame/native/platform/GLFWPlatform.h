#ifndef MOJAGAME_APP_PLATFORM_DESKTOP_H
#define MOJAGAME_APP_PLATFORM_DESKTOP_H

#include <GLFW/glfw3.h>
#include <cstdio>
#include <Mojagame/App.h>

// Forward declared
class App;

class Platform {

    public:
        int run( App* app );

};

#endif