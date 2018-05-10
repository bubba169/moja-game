#ifndef MOJAGAME_DISPLAY_QUAD_H
#define MOJAGAME_DISPLAY_QUAD_H

#include <Mojagame/Types.h>
#include <Mojagame/display/Sprite.h>
#include <Mojagame/util/Colour.h>

/**
 * A sprite is the base visual object. It has a render function and a transform.
 **/
class Quad : public Sprite {
    public:
        Quad(float width, float height, Colour colour);
        virtual void render( RenderContext* context );

        void setWidth(float width);
        void setHeight(float height);
        void setColour(Colour colour);

    private:
        float _width, _height;
        Colour _colour;
        std::vector<float> _points;
        std::vector<unsigned short> _indexes;
};

#endif