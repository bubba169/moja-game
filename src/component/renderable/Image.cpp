#include <Mojagame.h>

Image::Image(Sprite* sprite, std::string textureFilename) : Quad(sprite, 0, 0, COLOUR_WHITE) {
    Scene* scene = App::current()->getScene();
    if (!scene->textureLoaded(textureFilename)) {
        scene->loadTexture(textureFilename);
    }
}

void Quad::render(RenderContext* context) {
    context->drawTriangles(&_points, &_indexes, 0, getSprite()->getTransform()->getGlobalMatrix(), ;
}