#ifndef MOJAGAME_TEXTURE_H
#define MOJAGAME_TEXTURE_H

class Texture {
    // GL texture stuff
    public:
        Texture(std::string filename);
        ~Texture();
        void upload();

        GLuint getTextureId();
        int getWidth();
        int getHeight();

        int addUsage();
        int freeUsage();
        int getUsage();

    private:
        GLuint _textureId;
        std::string _filename;
        bool _isUploaded;
        int _width, _height, _channels, _originalChannels;
        unsigned char* _imageData;

        int _usageCount = 1;
};

#endif