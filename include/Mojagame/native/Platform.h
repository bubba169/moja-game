#ifndef MOJAGAME_APP_PLATFORM_DESKTOP_H
#define MOJAGAME_APP_PLATFORM_DESKTOP_H

// Forward declared
class App;

class Platform {

    public:
        int run( App* app );
        unsigned long timeInMilliseconds();

};

#endif