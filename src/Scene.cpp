#include <Mojagame.h>

/**
 * Scene
 */
Scene::Scene() {
    _context = new RenderContext();
}

Scene::~Scene() {
    delete _context;
    std::for_each(_textures.begin(), _textures.end(), [](std::pair<std::string, Texture*> val) {
        delete val.second;
    });
}

void Scene::init( float stageWidth, float stageHeight ) {
    _stageWidth = stageWidth;
    _stageHeight = stageHeight;
    _context->init();
}

void Scene::render() {
    _context->clear();
    Sprite::render(_context);
}

void Scene::resize(float width, float height, float pixelRatio) {

    float pixelWidth = width * pixelRatio;
    float pixelHeight = height * pixelRatio;

    _context->resize(pixelWidth, pixelHeight);

    float scale = fmin((pixelWidth)/_stageWidth, (pixelHeight)/_stageHeight);
    float x = 0, y = 0;

    getTransform()
        ->setScale(scale)
        ->setPosition((pixelWidth - (_stageWidth * scale)) * 0.5, (pixelHeight - (_stageHeight * scale)) * 0.5)
        ->globalToLocal(&x, &y);

    _marginLeft = -x;
    _marginTop = -y;
}

float Scene::getStageWidth() {
    return _stageWidth;
}

float Scene::getStageHeight() {
    return _stageHeight;
}

float Scene::getMarginLeft() {
    return _marginLeft;
}

float Scene::getMarginTop() {
    return _marginTop;
}

float Scene::getTotalWidth() {
    return getStageWidth() + (2 * getMarginLeft());
}

float Scene::getTotalHeight() {
    return getStageHeight() + (2 * getMarginTop());
}

float Scene::getLeft() {
    return -getMarginLeft();
}

float Scene::getRight() {
    return getStageWidth() + getMarginLeft();
}

float Scene::getTop() {
    return -getMarginTop();
}

float Scene::getBottom() {
    return getStageHeight() + getMarginTop();
}

void Scene::loadTexture(std::string filename) {
    Texture* texture = new Texture(filename);
    texture->upload();

    _textures[filename] = texture;
}

void Scene::freeTexture(std::string filename) {
    if (textureLoaded(filename)) {
        delete _textures[filename];
        _textures.erase(filename);
    }
}

void Scene::getTextureDimensions(std::string filename, int* width, int* height) {
    if (textureLoaded(filename)) {
        Texture* texture = _textures[filename];
        *width = texture->getWidth();
        *height = texture->getHeight();
    } else {
        *width = 0;
        *height = 0;
    }
}

bool Scene::textureLoaded(std::string filename) {
    return _textures.find(filename) != _textures.end();
}