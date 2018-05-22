#include <Mojagame.h>

/**
 * Sprites
 */
Sprite::Sprite() {
    _transform = new Transform(this);
}

Sprite::~Sprite() {
    delete _transform;
}

/**
 * Just renders children by default
 */
void Sprite::render( RenderContext* context ) {
    std::for_each( getTransform()->begin(), getTransform()->end(), [context](Transform* childTransform) {
        childTransform->getSprite()->render( context );
    });
}

Transform* Sprite::getTransform() {
    return _transform;
}