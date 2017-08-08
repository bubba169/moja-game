#ifndef MOJAGAME_SCENE_H
#define MOJAGAME_SCENE_H

#include <Mojagame/App.h>
#include <Mojagame/Grapevine.h>

// Forward declaration so Entity can see Scene
class App;

class Entity {

    public:
        Entity( App* app );
        //Transform* getTransform();
        Grapevine* getGrapevine();

    protected:
        App* _app;
        //Transform _transform;
        Grapevine _grapevine;
};

#endif