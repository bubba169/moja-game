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
        
        float t;

        void init() {
            App::init();

            getScene()->getEventDispatcher()->attach(this);
            
            sprite = new TestSprite();
            getScene()->getTransform()->addChild(sprite->getTransform());
        }

        bool onEvent(Event* event) {
            switch(event->type) {
                
            }
            return true;
        }

        void update(double seconds) {
            App::update(seconds);
        }
};

int main(int argc, char* argv[]) {
    setbuf(stdout, NULL);

    AppConfig config;
    config.title = "Simple Input";

    TestApp app(&config);
    return app.run(argc, argv);
}