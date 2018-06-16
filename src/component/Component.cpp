#include <Mojagame.h>

Component::Component(Sprite* sprite) : _sprite(sprite) {};
Component::~Component() {};

Sprite* Component::getSprite() {
    return _sprite;
}

