#pragma once

/**
 * An abstract renderable item that can be attached to a Sprite
 **/
class Renderable : public Component {
    public:
        Renderable(Sprite* sprite) : Component(sprite) {}
        virtual ~Renderable() {}
        virtual void render( RenderContext* context ) = 0;
};