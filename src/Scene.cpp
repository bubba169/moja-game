#include <Mojagame.h>

/**
 * Scene
 */
Scene::Scene() {
    __context = new RenderContext();
    __eventDispatcher = new EventDispatcher(this);
}

Scene::~Scene() {
    delete __context;
    delete __eventDispatcher;
}

void Scene::init( float stageWidth, float stageHeight ) {
    __stageWidth = stageWidth;
    __stageHeight = stageHeight;
    __context->init();
}

void Scene::render() {
    __context->clear();
    Sprite::render(__context);
}

void Scene::resize(float width, float height, float pixelRatio) {

    float pixelWidth = width * pixelRatio;
    float pixelHeight = height * pixelRatio;

    __context->resize(pixelWidth, pixelHeight);

    float scale = fmin((pixelWidth)/__stageWidth, (pixelHeight)/__stageHeight);
    float x = 0, y = 0;

    getTransform()
        ->setScale(scale)
        ->setPosition((pixelWidth - (__stageWidth * scale)) * 0.5, (pixelHeight - (__stageHeight * scale)) * 0.5)
        ->globalToLocal(&x, &y);

    __marginLeft = -x;
    __marginTop = -y;

    ResizeEvent event(width, height, pixelRatio);
    __eventDispatcher->dispatch(&event);
}

float Scene::getStageWidth() {
    return __stageWidth;
}

float Scene::getStageHeight() {
    return __stageHeight;
}

float Scene::getMarginLeft() {
    return __marginLeft;
}

float Scene::getMarginTop() {
    return __marginTop;
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

RenderContext* Scene::getRenderContext() {
    return __context;
}

EventDispatcher* Scene::getEventDispatcher() {
    return __eventDispatcher;
}