#ifndef MOJAGAME_SCENE_H
#define MOJAGAME_SCENE_H

#include <Mojagame/Types.h>
#include <Mojagame/display/Sprite.h>

class Scene : public Sprite {

    public:
        Scene();
        virtual ~Scene();

        void resize( int width, int height, float pixelRatio );
        void init( int stageWidth, int stageHeight );
        void render();

    protected:
        RenderContext* _context;
        int _stageWidth, _stageHeight;

};

#endif