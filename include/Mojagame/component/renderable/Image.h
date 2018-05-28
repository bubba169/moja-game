#ifndef MOJAGAME_RENDERABLE_IMAGE_H
#define MOJAGAME_RENDERABLE_IMAGE_H

class Image : public Quad {
    public:
        Image(Sprite* sprite, std::string textureFilename);

        virtual void render(RenderContext* context);

    private:
        std::vector<std::string> _textureFilenames;
};

#endif