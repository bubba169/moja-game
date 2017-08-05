#include <cstdio>
#include <GLFW/glfw3.h>
#include <Mojagame/App.h>

using namespace std;

int main() {

    setbuf(stdout, NULL);
    printf("Hello World\n");

    AppConfig config;
    config.windowWidth = 1280;
    config.windowHeight = 800;
    config.title = "My First App";

    App app( &config );
    return app.run();
}