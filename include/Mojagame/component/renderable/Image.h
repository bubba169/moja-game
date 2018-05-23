#ifndef MOJAGAME_RENDERABLE_IMAGE_H
#define MOJAGAME_RENDERABLE_IMAGE_H

class Image : public Quad {
    public:
        Image(Sprite* sprite, float width, float height, int textureId);

    private:
        int _textureId;
};

#endif