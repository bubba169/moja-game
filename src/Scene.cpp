#include <Mojagame/Scene.h>
#include <Mojagame/Renderer.h>

/**
 * Scene
 */
Scene::Scene() {
    _context = new RenderContext();
}

Scene::~Scene() {
    delete _context;
}

void Scene::init() {
    _context->init();
}

void Scene::render() {
    _context->clear();
    Sprite::render(_context);

    /*std::vector<float> verts = {
        0, 0, 1.0, 1.0, 1.0, 1.0,
        200, 0, 1.0, 1.0, 1.0, 1.0,
        100, 200, 1.0, 1.0, 1.0, 1.0
    };

    std::vector<unsigned short> inds = {
        0, 2, 1
    };

    _context->drawTriangles(&verts, &inds, 0);*/


}

void Scene::resize(int width, int height) {
    _context->resize(width, height);
}