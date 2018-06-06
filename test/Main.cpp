#include <Mojagame.h>

class TestSprite : public Sprite {
    public:
        TestSprite() {
            printf("Creating renderable\n");
            setRenderable((new Image(this, "/home/simon/Projects/moja-game/output/test2.png", 500, 500))->setSourceUV(0, 0, 1, 1)->setAlpha(0.8));
        }
};

class TestApp : public App {
    public:
        TestApp(AppConfig* config) : App(config) {}
        TestSprite* sprite;
        TestSprite* parent;

        void init() {
            App::init();

            parent = new TestSprite();
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
            //((Quad*)(parent->getRenderable()))->setSize(getScene()->getTotalWidth(), getScene()->getTotalHeight());
        }
};

int main() {
    setbuf(stdout, NULL);
    printf("Hello World\n");

    AppConfig config;
    config.title = "MoJaGame Demo";

    TestApp app(&config);
    return app.run();
}