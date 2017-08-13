#ifndef MOJAGAME_APP_PLATFORM_DESKTOP_H
#define MOJAGAME_APP_PLATFORM_DESKTOP_H

#ifdef DESKTOP
    #include <GLFW/glfw3.h>
#endif

#include <cstdio>
#include <Mojagame/App.h>

#ifdef POSIX 
    #include <sys/time.h>
#endif

// Forward declared
class App;

class Platform {

    public:
        int run( App* app );
        unsigned long timeInMilliseconds();

};

#endif