#include <cstdio>
#include <GLFW/glfw3.h>
#include <Mojagame/App.h>

using namespace std;

/**
 * Pass this in just for the sake of testing
 */
class TestEngine : public GameEngine {
    void init( App* app ) {
        printf("Test engine init\n");
    }
};

int main() {

    setbuf(stdout, NULL);
    printf("Hello World\n");

    AppConfig config;
    config.windowWidth = 1280;
    config.windowHeight = 800;
    config.title = "My First App";

    TestEngine engine;
    App app( &config, &engine );
    return app.run();
}