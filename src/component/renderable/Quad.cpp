#include <Mojagame.h>

Quad::Quad(Sprite* sprite, float width, float height, Colour colour) : Quad(sprite, width, height, colour, 6) {}

Quad::Quad(Sprite* sprite, float width, float height, Colour colour, int vertexSize) : Renderable(sprite), _vertexSize(vertexSize) {
    _points.resize(4 * _vertexSize, 0.0f);

    /**
     * Items are stored in _points as 
     * [ 
     *   0, 0, r, g, b, a,
     *   0, h, r, g, b, a,
     *   w, h, r, g, b, a,
     *   w, 0, r, g, b, a
     * ]
     */

    //_vertexSize = 6;

    setWidth(width);
    setHeight(height);
    setColour(colour);

    _indexes.push_back(0);
    _indexes.push_back(1);
    _indexes.push_back(2);
    _indexes.push_back(0);
    _indexes.push_back(2);
    _indexes.push_back(3);
}

void Quad::setWidth(float width) {
    _points[_vertexSize * 2] = _points[_vertexSize * 3] = _width = width; 
}

void Quad::setHeight(float height) {
    _points[_vertexSize + 1] = _points[(_vertexSize * 2) + 1] = _height = height; 
}

void Quad::setSize(float width, float height) {
    setWidth(width);
    setHeight(height);
}

void Quad::setColour(Colour colour) {
    _colour = colour;
    for (int i = 0; i < 4; i++) {
        _points[(_vertexSize * i) + 2] = colour.getRed() / 255.0f;
        _points[(_vertexSize * i) + 3] = colour.getGreen() / 255.0f;
        _points[(_vertexSize * i) + 4] = colour.getBlue() / 255.0f;
        _points[(_vertexSize * i) + 5] = colour.getAlpha();
    }    
}

void Quad::render(RenderContext* context) {
    context->drawTriangles(&_points, &_indexes, SHADER_COLOUR, getSprite()->getTransform()->getGlobalMatrix());
}

float Quad::getWidth() {
    return _width;
}

float Quad::getHeight() {
    return _height;
}

Colour Quad::getColour() {
    return _colour;
}