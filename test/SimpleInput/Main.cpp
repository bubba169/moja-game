#include <Mojagame.h>

class TestSprite : public Sprite {
    public:
        TestSprite() {
            setRenderable((new Quad(this))->setSize(100, 100)->setColour(COLOUR_RED));
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

            getScene()->getEventDispatcher()->attach(this);

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
            t = fmod(t + seconds, M_PI);
            ((Quad*)(parent->getRenderable()))->setAlpha( sin(t) );

        }

        void shutdown() {
            App::shutdown();
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