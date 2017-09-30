#include <Mojagame/component/renderer/QuadComponent.h>
#include <Mojagame/Renderer.h>
#include <Mojagame/component/Transform.h>
#include <Mojagame/Entity.h>

QuadComponent::QuadComponent() : _colour(COLOUR_WHITE), _vertsDirty(true) {
    _vertices.assign(24, 0);
    _indexes = {1,2,3,1,3,4};
}

QuadComponent::QuadComponent(int width, int height, Colour colour) : _colour(colour), _vertsDirty(true), _width(width), _height(height) {
    _vertices.assign(24, 0);
    _indexes = {1,2,3,1,3,4};
}

std::string QuadComponent::getName() {
    return "Quad";
}

void QuadComponent::render( RenderContext* context ) {

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

            Transform* transform = (Transform*)(getEntity()->find("Transform"));
            transform->localToGlobal( &_vertices[n+0], &_vertices[n+1] );

            _vertices[n+2] = _colour.getRed() / 255.0;
            _vertices[n+4] = _colour.getGreen() / 255.0;
            _vertices[n+3] = _colour.getBlue() / 255.0;
            _vertices[n+5] = _colour.getAlpha();
        }
    }

    context->drawTriangles( &_vertices, &_indexes, SHADER_COLOUR );
}