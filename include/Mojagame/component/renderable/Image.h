#ifndef MOJAGAME_RENDERABLE_IMAGE_H
#define MOJAGAME_RENDERABLE_IMAGE_H

class Image : public Quad {
    public:
        Image(Sprite* sprite, std::string textureFilename);

    private:
        std::string _textureFilenames[1];
};

#endif