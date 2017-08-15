#include <cstdio>
#include <GLFW/glfw3.h>

#include <Mojagame/App.h>
#include <Mojagame/component/renderer/QuadRenderer.h>
#include <Mojagame/Entity.h>
#include <Mojagame/Factory.h>
#include <Mojagame/Scene.h>
#include <Mojagame/component/Transform.h>

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

    printf("Finding component\n");

    Component* component = entity->find("QuadRenderer");
    std::string name = component->getName();

    app.getScene()->getRoot()->addChild( entity->getTransform() );

    printf("Found component %s\n", name.c_str());

    return app.run();
}