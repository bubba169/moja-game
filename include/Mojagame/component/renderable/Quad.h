#pragma once

/**
 * A sprite is the base visual object. It has a render function and a transform.
 **/
class Quad : public Renderable {
    public:
        Quad(Sprite* sprite);
        virtual void render( RenderContext* context );

        float getWidth();
        float getHeight();
        Colour getColour();
        Quad* setWidth(float width);
        Quad* setHeight(float height);
        Quad* setSize(float width, float height);
        Quad* setColour(Colour colour);

        Quad* setAlpha(float alpha);
        float getAlpha();


    protected:
        Quad(Sprite* sprite, int vertexSize);
        std::vector<float> _points;
        std::vector<unsigned short> _indexes;
        int _vertexSize;

    private:
        float _width, _height;
        Colour _colour;
};