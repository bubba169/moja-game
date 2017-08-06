#ifndef MOJAGAME_APP_PLATFORM_DESKTOP_H
#define MOJAGAME_APP_PLATFORM_DESKTOP_H

#include <GLFW/glfw3.h>
#include <cstdio>
#include <Mojagame/App.h>

#if defined(LINUX) || defined(MAC) 
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