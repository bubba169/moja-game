#include <Mojagame/display/Quad.h>
#include <Mojagame/component/Transform.h>
#include <Mojagame/Renderer.h>

Quad::Quad(float width, float height, Colour colour) {
    _points.resize(4 * 6, 0.0f);

    /**
     * Items are stored in _points as 
     * [ 
     *   0, 0, r, g, b, a,
     *   0, h, r, g, b, a,
     *   w, h, r, g, b, a,
     *   w, 0, r, g, b, a
     * ]
     */

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
    _points[12] = _points[18] = _width = width; 
}

void Quad::setHeight(float height) {
    _points[7] = _points[13] = _height = height; 
}

void Quad::setColour(Colour colour) {
    _points[2] = _points[8] = _points[14] = _points[20] = colour.getRed() / 255.0f; 
    _points[3] = _points[9] = _points[15] = _points[21] = colour.getGreen() / 255.0f; 
    _points[4] = _points[10] = _points[16] = _points[22] = colour.getBlue() / 255.0f; 
    _points[5] = _points[11] = _points[17] = _points[23] = colour.getAlpha(); 
    _colour = colour;
}

void Quad::render(RenderContext* context) {
    context->drawTriangles(&_points, &_indexes, 0, getTransform()->getGlobalMatrix());
    Sprite::render(context);
}