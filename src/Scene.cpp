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
    _context->resize(width * pixelRatio, height * pixelRatio);

    float scale = fmin((float)width/_stageWidth, (float)height/_stageHeight);
    getTransform()
        ->setScale(scale)
        // Force the matrix to regenerate as this never gets drawn
        ->getGlobalMatrix();
}