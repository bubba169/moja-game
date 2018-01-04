#include <cstdio>
#include <Mojagame/App.h>
#include <Mojagame/display/Sprite.h>
#include <Mojagame/component/Transform.h>

class TestApp : public App {
    public:
        TestApp(AppConfig* config) : App(config) {}

        void init() {
            App::init();

            Sprite sprite;
            sprite.getTransform()->setPosition(20, 20)->setRotationDegrees(180)->setScale(2);
            sprite.getTransform()->getGlobalMatrix()->print();

            Sprite s2;
            sprite.getTransform()->addChild(s2.getTransform());
            s2.getTransform()->getGlobalMatrix()->print();
        }

        void update(double seconds) {
            App::update(seconds);
        }

        void render(RenderContext* context) {
            App::render(context);
        }

        void shutdown() {
            App::shutdown();
        }

        void resize(int width, int height) {
            App::resize(width, height);
            printf("Resize %i %i\n", width, height);
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