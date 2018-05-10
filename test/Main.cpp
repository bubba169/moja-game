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

        void init() {
            App::init();
            sprite = new Quad(100, 100, COLOUR_BLUE);
            getScene()->getTransform()->addChild( sprite->getTransform() );
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

        void resize(int width, int height) {
            App::resize(width, height);
        }
};

int main() {
    setbuf(stdout, NULL);
    printf("Hello World\n");

    AppConfig config;
    config.windowWidth = 1280;
    config.windowHeight = 800;
    config.title = "MoJaGame Demo";

    TestApp app(&config);
    return app.run();
}