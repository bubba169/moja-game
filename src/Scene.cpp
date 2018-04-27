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

    std::vector<float> verts = {
        100, 100, 1.0, 1.0, 1.0, 1.0,
        200, 100, 1.0, 1.0, 1.0, 1.0,
        150, 200, 1.0, 1.0, 1.0, 1.0
    };

    std::vector<unsigned short> inds = {
        0, 2, 1
    };

    _context->drawTriangles(&verts, &inds, 0);
}

void Scene::resize(int width, int height) {
    _context->resize(width, height);
}