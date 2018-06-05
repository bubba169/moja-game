
/**
 * Define this here to include the STB Image function only once
 */
#define STB_IMAGE_IMPLEMENTATION
#include <Mojagame.h>

Texture::Texture(std::string filename) : _filename(filename), _isUploaded(false), _channels(4), _width(0), _height(0), _originalChannels(0) {
    _imageData = stbi_load(_filename.c_str(), &_width, &_height, &_originalChannels, _channels);

    if (_originalChannels == 0) {
        printf("Failed to load image at %s\n", _filename.c_str());
    } else {
        printf("Loaded texture %s %i x %i @ %i %i\n", _filename.c_str(), _width, _height, _originalChannels, _width * _height * _channels );
    }

    glGenTextures(1, &_textureId);
}

Texture::~Texture() {
    stbi_image_free(_imageData);
}

void Texture::upload() {
    glBindTexture(GL_TEXTURE_2D, _textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _imageData);
    glBindTexture(GL_TEXTURE_2D, 0);
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

GLuint Texture::getTextureId() {
    return _textureId;
}