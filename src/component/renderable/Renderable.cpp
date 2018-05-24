#include <Mojagame.h>

Renderable::Renderable(Sprite* sprite) : _sprite(sprite) {};
Renderable::~Renderable() {};

Sprite* Renderable::getSprite() {
    return _sprite;
}

