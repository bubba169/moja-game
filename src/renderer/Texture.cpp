
/**
 * Define this here to include the STB Image function only once
 */
#define STB_IMAGE_IMPLEMENTATION
#include <Mojagame.h>

Texture::Texture(std::string filename) : _filename(filename), _isUploaded(false), _channels(4) {
    _imageData = stbi_load(_filename.c_str(), &_width, &_height, &_originalChannels, _channels);
    glGenTextures(1, &_textureId);

    printf("Texture %i\n", _textureId );
}

Texture::~Texture() {
    stbi_image_free(_imageData);
}

void Texture::upload() {
    glBindTexture(GL_TEXTURE_2D, _textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _imageData);
    _isUploaded = true;
}

int Texture::getWidth() {
    return _width;
}

int Texture::getHeight() {
    return _height;
}

int Texture::addUsage() {
    return ++_usageCount;
}

int Texture::freeUsage() {
    return --_usageCount;
}

int Texture::getUsage() {
    return _usageCount;
}