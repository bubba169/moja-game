#ifndef MOJAGAME_RENDERABLE_H
#define MOJAGAME_RENDERABLE_H

/**
 * An abstract renderable item that can be attached to a Sprite
 **/
class Renderable {
    public:
        Renderable(Sprite* sprite);
        virtual void render( RenderContext* context ) = 0;
        Sprite* getSprite();
    private:
        Sprite* _sprite;
};

#endif