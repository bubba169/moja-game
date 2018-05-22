#include <Mojagame.h>

Renderable::Renderable(Sprite* sprite) : _sprite(sprite) {};

Sprite* Renderable::getSprite() {
    return _sprite;
}

