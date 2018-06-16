#pragma once

/**
 * An abstract renderable item that can be attached to a Sprite
 **/
class Renderable {
    public:
        Renderable(Sprite* sprite);
        virtual ~Renderable();
        virtual void render( RenderContext* context ) = 0;
        Sprite* getSprite();
    private:
        Sprite* _sprite;
};