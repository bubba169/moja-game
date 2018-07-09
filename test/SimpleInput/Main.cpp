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

            float speed = 400;

            //printf("%i\n", getInputMap()->isKeyDown(KEYBOARD_KEY_LEFT));
            if (getInputMap()->isKeyDown(KEYBOARD_KEY_LEFT)) {
                sprite->getTransform()->moveBy(-speed * seconds, 0);
            }

            if (getInputMap()->isKeyDown(KEYBOARD_KEY_UP)) {
                sprite->getTransform()->moveBy(0, -speed * seconds);
            } 

            if (getInputMap()->isKeyDown(KEYBOARD_KEY_RIGHT)) {
                sprite->getTransform()->moveBy(speed * seconds, 0);
            } 

            if (getInputMap()->isKeyDown(KEYBOARD_KEY_DOWN)) {
                sprite->getTransform()->moveBy(0, speed * seconds);
            } 
        }
};

int main(int argc, char* argv[]) {
    setbuf(stdout, NULL);

    AppConfig config;
    config.title = "Simple Input";

    TestApp app(&config);
    return app.run(argc, argv);
}