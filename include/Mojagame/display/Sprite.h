#ifndef MOJAGAME_DISPLAY_SPRITE_H
#define MOJAGAME_DISPLAY_SPRITE_H

#include <Mojagame/Types.h>

/**
 * A sprite is the base visual object. It has a render function and a transform.
 **/
class Sprite {
    public:
        Sprite();
        virtual ~Sprite();

        virtual void render( RenderContext* context );

        // Getters
        Transform* getTransform();
        
    private:
        Transform* _transform;
};

#endif