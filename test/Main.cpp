#include <Mojagame.h>

class TestSprite : public Sprite {
    public:
        TestSprite() {
            setRenderable((new Image(this, App::current()->getPath("test.png"), 500, 500))->setSourceUV(0, 0, 1, 1)->setAlpha(0.5));
        }
};

class TestApp : public App {
    public:
        TestApp(AppConfig* config) : App(config) {}
        TestSprite* sprite;
        TestSprite* parent;
        float t;

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

            t = t + seconds;
            if (t > M_PI) t -= M_PI;
            ((Quad*)(parent->getRenderable()))->setAlpha( sin(t) );

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

int main(int argc, char* argv[]) {
    setbuf(stdout, NULL);
    printf("Hello World\n");

    AppConfig config;
    config.title = "MoJaGame Demo";

    TestApp app(&config);
    return app.run(argc, argv);
}