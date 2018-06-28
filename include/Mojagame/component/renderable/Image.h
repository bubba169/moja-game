#pragma once

class Image : public Quad {
    public:
        Image(Sprite* sprite, std::string textureFilename);
        virtual ~Image();

        virtual void render(RenderContext* context);
        Image* setSourceRect(int x, int y, int width, int height);
        Image* setSourceUV(float x, float y, float width, float height);

    protected:
        void initTexture(std::string filename);

    private:
        std::vector<std::string> _textureFilenames;
};