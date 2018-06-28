#include <Mojagame.h>

/**
 * Items are stored in _points as 
 * [ 
 *   0, 0, r, g, b, a, u, v,
 *   0, h, r, g, b, a, u, v,
 *   w, h, r, g, b, a, u, v,
 *   w, 0, r, g, b, a, u, v
 * ]
 */

Image::Image(Sprite* sprite, std::string textureFilename) : Quad(sprite, 8) {
    initTexture(textureFilename);
    RenderContext* context = App::current()->getScene()->getRenderContext();

    // Default to image width/height
    int w, h;
    context->getTextureDimensions(textureFilename, &w, &h);
    printf("Size %i %i\n", w, h);
    setSize(w, h);
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
    context->drawTriangles(&_points, &_indexes, SHADER_TEXTURE, getSprite()->getTransform()->getGlobalMatrix(), &_textureFilenames);
}

Image* Image::setSourceRect(int x, int y, int width, int height) {
    int w, h;
    RenderContext* context = App::current()->getScene()->getRenderContext();
    context->getTextureDimensions(_textureFilenames[0], &w, &h);

    return setSourceUV((float)x / w, (float)y / h, (float)width / w, (float)height / h);
}

Image* Image::setSourceUV(float x, float y, float width, float height) {
    _points[6] = _points[_vertexSize + 6] = x;
    _points[7] = _points[(_vertexSize * 3) + 7] = y;
    _points[(_vertexSize * 2) + 6] = _points[(_vertexSize * 3) + 6] = x + width;
    _points[_vertexSize + 7] = _points[(_vertexSize * 2) + 7] = y + height;
    return this;
}