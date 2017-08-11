#include <cstdio>
#include <GLFW/glfw3.h>

#include <Mojagame/App.h>
#include <Mojagame/component/renderer/QuadRenderer.h>

using namespace std;

/**
 * Pass this in just for the sake of testing
 */
class TestEngine : public GameEngine {
    public:
        void init( App* app ) {
            printf("Test engine init\n");
        }
};

class TestGenerator : public Generator {
    public:
        void generate( Entity* entity ) {
            printf("Generating Test Entity\n");
            entity->add( new QuadRenderer() );
        }
};

int main() {
    setbuf(stdout, NULL);
    printf("Hello World\n");

    AppConfig config;
    config.windowWidth = 1280;
    config.windowHeight = 800;
    config.title = "MoJaGame Demo";

    TestEngine engine;
    App app( &config, &engine );

    app.getFactory()->registerGenerator( 1, new TestGenerator() );
    Entity* entity = app.getFactory()->create(1);

    Component* component = entity->find("QuadRenderer");
    std::string name = component->getName();

    delete entity->remove("QuadComponent");
    component = entity->find("QuadComponent");

    return app.run();
}