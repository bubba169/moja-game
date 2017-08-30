#include <Mojagame/component/renderer/QuadRenderer.h>
#include <Mojagame/native/renderer/RenderContext.h>
#include <Mojagame/component/Transform.h>

QuadRenderer::QuadRenderer() : _colour(Colours::White), _vertsDirty(true) {
    _vertices->reserve(24);
    _indices->reserve(6);
}

QuadRenderer::QuadRenderer(int width, int height, Colour colour) : _colour(colour), _vertsDirty(true), _size(width, height) {
    _vertices->reserve(24);
    _indices->reserve(6);
}

std::string QuadRenderer::getName() {
    return "QuadRenderer";
}

void QuadRenderer::render( RenderContext* context ) {

    if ( _vertsDirty ) {

        for( int i = 0; i < 4; i++ ) {

            int n = i * 6;

            switch(i) {
                case 0:
                    // top left
                    _vertices[n+0] = 0;
                    _vertices[n+1] = 0;
                    break;
                case 1:
                    _vertices[n+0] = 0;
                    _vertices[n+1] = _height;
                    break;
                case 2:
                    _vertices[n+0] = _width;
                    _vertices[n+1] = _height;
                    break;
                case 3:
                    _vertices[n+0] = _width;
                    _vertices[n+1] = 0;
                    break;
            }

            Transform* transform = getEntity().find('Transform');
            transform->transformPoint( &_vertices[n+0], &_vertices[n+1] );

            _vertices[n+2] = _colour.getRed() / 255.0;
            _vertices[n+4] = _colour.getGreen() / 255.0;
            _vertices[n+3] = _colour.getBlue() / 255.0;
            _vertices[n+5] = _colour.getAlpha();
    }
    context->drawElement( _vertices, _indexes, RenderFlags::Colour )
}