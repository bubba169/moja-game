#ifndef MOJAGAME_SCENE_H
#define MOJAGAME_SCENE_H

#include <Mojagame/Types.h>
#include <Mojagame/display/Sprite.h>

class Scene : Sprite {

    public:
        Scene();
        virtual ~Scene();

        void resize( int width, int height );

    protected:

};

#endif