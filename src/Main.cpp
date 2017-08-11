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

    entity->add( new QuadRenderer() );
    Component* component = entity->find("Component");

    printf("Got component with name %s\n", component->getName().c_str());

    delete entity->remove("Component");
    component = entity->find("Component");

    printf("Deleted component %i\n", component == NULL);

    return app.run();
}