#include <cstdio>
#include <Mojagame/App.h>

class TestApp : public App {
    public:
        TestApp(AppConfig* config) : App(config) {}

        void init() {
            App::init();
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