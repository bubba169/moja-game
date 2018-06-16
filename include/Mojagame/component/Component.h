#pragma once

/**
 * An abstract item that can be attached to a Sprite
 **/
class Sprite;

class Component {
    public:
        Component(Sprite* sprite);
        virtual ~Component();

        Sprite* getSprite();
    private:
        Sprite* _sprite;
};