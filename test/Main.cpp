#include <cstdio>
#include <Mojagame/App.h>
#include <Mojagame/display/Sprite.h>
#include <Mojagame/display/Quad.h>
#include <Mojagame/component/Transform.h>
#include <Mojagame/Scene.h>

class TestApp : public App {
    public:
        TestApp(AppConfig* config) : App(config) {}
        Quad* sprite;
        Quad* parent;

        void init() {
            App::init();

            parent = new Quad(0, 0, COLOUR_BLUE);
            getScene()->getTransform()->addChild(parent->getTransform());
        }

        void update(double seconds) {
            App::update(seconds);
        }

        void render() {
            App::render();
        }

        void shutdown() {
            App::shutdown();
        }

        void resize(int width, int height, float pixelRatio) {
            App::resize(width, height, pixelRatio);

            parent->getTransform()->setPosition(getScene()->getLeft(), getScene()->getTop());
            parent->setSize(getScene()->getTotalWidth(), getScene()->getTotalHeight());
        }
};

int main() {
    setbuf(stdout, NULL);
    printf("Hello World\n");

    AppConfig config;
    config.title = "MoJaGame Demo";
    config.windowWidth = 650;

    TestApp app(&config);
    return app.run();
}