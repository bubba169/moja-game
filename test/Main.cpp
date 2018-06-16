#include <Mojagame.h>

class TestSprite : public Sprite {
    public:
        TestSprite() {
            setRenderable((new Image(this, App::current()->getPath("test.png"), 500, 500))->setSourceUV(0, 0, 1, 1)->setAlpha(0.5));
        }
};

class TestApp : public App, public IEventListener {
    public:
        TestApp(AppConfig* config) : App(config) {}
        TestSprite* sprite;
        TestSprite* parent;
        float t;

        void init() {
            App::init();

            getEventDispatcher()->attach(this);

            parent = new TestSprite();
            getScene()->getTransform()->addChild(parent->getTransform());

            sprite = new TestSprite();

            //getGrapevine()->listen(SYSTEM_MESSAGE_RESIZE, std::bind(&TestApp::onResize, this, std::placeholders::_1, std::placeholders::_2));
        }

        bool onEvent(Event* event) {
            switch(event->type) {
                case EventType::Resize: {
                    ResizeEvent* resizeEvent = (ResizeEvent*)event;
                    return onResize(resizeEvent->width, resizeEvent->height, resizeEvent->pixelRatio);
                }
            }
            return true;
        }

        bool onResize(int width, int height, float pixelRatio) {
            printf("%i %i %f\n", width, height, pixelRatio);
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