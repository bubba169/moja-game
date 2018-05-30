#ifndef MOJAGAME_RENDERABLE_IMAGE_H
#define MOJAGAME_RENDERABLE_IMAGE_H

class Image : public Quad {
    public:
        Image(Sprite* sprite, std::string textureFilename);
        Image(Sprite* sprite, std::string textureFilename, float width, float height);
        virtual ~Image();

        virtual void render(RenderContext* context);

    protected:
        void initTexture(std::string filename);

    private:
        std::vector<std::string> _textureFilenames;
};

#endif