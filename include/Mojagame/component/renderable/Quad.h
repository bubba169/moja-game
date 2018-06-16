#pragma once

/**
 * A sprite is the base visual object. It has a render function and a transform.
 **/
class Quad : public Renderable {
    public:
        Quad(Sprite* sprite, float width, float height, Colour colour);
        virtual void render( RenderContext* context );

        float getWidth();
        float getHeight();
        Colour getColour();
        void setWidth(float width);
        void setHeight(float height);
        void setSize(float width, float height);
        void setColour(Colour colour);

        Quad* setAlpha(float alpha);
        float getAlpha();


    protected:
        Quad(Sprite* sprite, float width, float height, Colour colour, int vertexSize);
        std::vector<float> _points;
        std::vector<unsigned short> _indexes;
        int _vertexSize;

    private:
        float _width, _height;
        Colour _colour;
};