#include <Mojagame.h>

/**
 * Sprites
 */
Sprite::Sprite() {
    _transform = new Transform(this);
    _renderable = NULL;
}

void Sprite::setRenderable(Renderable* renderable) {
    _renderable = renderable;
}

Sprite::~Sprite() {
    delete _transform;
    if (_renderable) {
        delete _renderable;
    }
}

/**
 * Just renders children by default
 */
void Sprite::render( RenderContext* context ) {
    if (_renderable) {
        _renderable->render(context);
    }

    std::for_each( getTransform()->begin(), getTransform()->end(), [context](Transform* childTransform) {
        childTransform->getSprite()->render( context );
    });
}

Transform* Sprite::getTransform() {
    return _transform;
}

Renderable* Sprite::getRenderable() {
    return _renderable;
}