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

            parent = new Quad(1280, 800, COLOUR_BLUE);
            //parent->getTransform()->setPosition(200, 200);
            getScene()->getTransform()->addChild(parent->getTransform());

            sprite = new Quad(1280, 800, COLOUR_RED);
            sprite->getTransform()->setPosition(0, 0);
            //parent->getTransform()->addChild(sprite->getTransform());
        }

        void update(double seconds) {
            App::update(seconds);
            //sprite->getTransform()->setRotationDegrees( sprite->getTransform()->getRotationDegrees() + (100 * seconds) );
            //parent->getTransform()->setRotationDegrees( parent->getTransform()->getRotationDegrees() + (50 * seconds) );
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
            parent->getTransform()->getGlobalMatrix()->print();
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