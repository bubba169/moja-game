#include <Mojagame.h>

Image::Image(Sprite* sprite, std::string textureFilename) : Quad(sprite, 0, 0, COLOUR_WHITE) {
    initTexture(textureFilename);

    int w, h;
    RenderContext* context = App::current()->getScene()->getRenderContext();
    context->getTextureDimensions(textureFilename, &w, &h);
    setSize(w, h);
}

Image::Image(Sprite* sprite, std::string textureFilename, float width, float height) : Quad(sprite, width, height, COLOUR_WHITE) {
    initTexture(textureFilename);
}

Image::~Image() {
    RenderContext* context = App::current()->getScene()->getRenderContext();
    context->freeTexture(_textureFilenames[0]);
}

void Image::initTexture(std::string textureFilename) {
    _textureFilenames.push_back(textureFilename);
    RenderContext* context = App::current()->getScene()->getRenderContext();
    context->loadTexture(textureFilename);
}

void Image::render(RenderContext* context) {
    context->drawTriangles(&_points, &_indexes, 0, getSprite()->getTransform()->getGlobalMatrix(), &_textureFilenames);
}