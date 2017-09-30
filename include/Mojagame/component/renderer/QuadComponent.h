#ifndef COMPONENTS_QUAD_RENDERER_H
#define COMPONENTS_QUAD_RENDERER_H

#include <Mojagame/Types.h>
#include <Mojagame/component/renderer/RenderComponent.h>
#include <Mojagame/util/Colour.h>
#include <Mojagame/math/Vector.h>

class QuadComponent : public RenderComponent {

    public:
        QuadComponent();
        QuadComponent(int width, int height, Colour colour);

        virtual std::string getName();
        virtual void render( RenderContext* context );

    protected:
        float _height, _width;
        Colour _colour;

        std::vector<float> _vertices;
        std::vector<unsigned short> _indexes;

        bool _vertsDirty;
};

#endif