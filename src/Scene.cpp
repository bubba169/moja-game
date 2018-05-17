#include <Mojagame/Scene.h>
#include <Mojagame/Renderer.h>
#include <Mojagame/component/Transform.h>

/**
 * Scene
 */
Scene::Scene() {
    _context = new RenderContext();
}

Scene::~Scene() {
    delete _context;
}

void Scene::init( int stageWidth, int stageHeight ) {
    _stageWidth = stageWidth;
    _stageHeight = stageHeight;
    _context->init();
}

void Scene::render() {
    _context->clear();
    Sprite::render(_context);
}

void Scene::resize(int width, int height, float pixelRatio) {

    int pixelWidth = width * pixelRatio;
    int pixelHeight = height * pixelRatio;

    _context->resize(pixelWidth, pixelHeight);

    float scale = fmin(((float)pixelWidth)/_stageWidth, ((float)pixelHeight)/_stageHeight);
    float x = 0, y = 0;

    getTransform()
        ->setScale(scale)
        ->setPosition((pixelWidth - (_stageWidth * scale)) * 0.5, (pixelHeight - (_stageHeight * scale)) * 0.5)
        ->getGlobalMatrix();
    
    getTransform()->globalToLocal(&x, &y);

    _marginLeft = x;
    _marginTop = y;

    printf("%f\n", scale);
}

int Scene::getStageWidth() {
    return _stageWidth;
}

int Scene::getStageHeight() {
    return _stageHeight;
}

int Scene::getMarginLeft() {
    return _marginLeft;
}

int Scene::getMarginTop() {
    return _marginTop;
}

int Scene::getTotalWidth() {
    return getStageWidth() + (2 * getMarginLeft());
}

int Scene::getTotalHeight() {
    return getStageHeight() + (2 * getMarginTop());
}

int Scene::getLeft() {
    return -getMarginLeft();
}

int Scene::getRight() {
    return getStageWidth() + getMarginLeft();
}

int Scene::getTop() {
    return -getMarginTop();
}

int Scene::getBottom() {
    return getStageHeight() + getMarginTop();
}