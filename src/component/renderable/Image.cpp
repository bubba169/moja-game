#include <Mojagame.h>

Image::Image(Sprite* sprite, std::string textureFilename) : Quad(sprite, 0, 0, COLOUR_WHITE) {
    _textureFilenames.push_back(textureFilename);
    RenderContext* context = App::current()->getScene()->getRenderContext();
    if (!context->textureLoaded(textureFilename)) {
        context->loadTexture(textureFilename);
    }
}

void Image::render(RenderContext* context) {
    context->drawTriangles(&_points, &_indexes, 0, getSprite()->getTransform()->getGlobalMatrix(), &_textureFilenames);
}