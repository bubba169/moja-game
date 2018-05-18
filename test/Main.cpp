#include <cstdio>
#include <Mojagame/App.h>
#include <Mojagame/display/Sprite.h>
#include <Mojagame/display/Quad.h>
#include <Mojagame/component/Transform.h>
#include <Mojagame/Scene.h>
#include <Mojagame/Grapevine.h>

class TestApp : public App {
    public:
        TestApp(AppConfig* config) : App(config) {}
        Quad* sprite;
        Quad* parent;

        void init() {
            App::init();

            parent = new Quad(0, 0, COLOUR_BLUE);
            getScene()->getTransform()->addChild(parent->getTransform());

            getGrapevine()->listen(SYSTEM_MESSAGE_RESIZE, std::bind(&TestApp::onResize, this, std::placeholders::_1, std::placeholders::_2));
        }

        bool onResize(int message, Bundle* size) {
            printf("%i %i\n", size->get<int>("width"), size->get<int>("height"));
            return true;
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