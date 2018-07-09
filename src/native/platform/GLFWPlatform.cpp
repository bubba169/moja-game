#include <Mojagame.h>

void glfw_error(int i, const char* error) {
    printf("ERROR: %i %s\n", i, error);
}

void resize(GLFWwindow* window) {
    int currentWidth, currentHeight, currentPixelWidth, currentPixelHeight;

    glfwGetFramebufferSize(window, &currentPixelWidth, &currentPixelHeight);
    glfwGetWindowSize(window, &currentWidth, &currentHeight);

    App::current()->resize(currentWidth, currentHeight, (float)currentPixelWidth / currentWidth);
}

void glfw_resizeCallback(GLFWwindow* window, int width, int height) {
   resize(window);
}

void glfw_keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        App::current()->getInputMap()->onKeyDown(key);
    } else if (action == GLFW_RELEASE) {
        App::current()->getInputMap()->onKeyUp(key);
    }
}

int Platform::run( App* app ) {

    // Get the app config
    AppConfig* config = app->getConfig();
    
    // Initialise GLFW
    if (!glfwInit()) return -1;

    // Create a window
    GLFWwindow* window = glfwCreateWindow( config->windowWidth, config->windowHeight, config->title, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwSetKeyCallback(window, glfw_keyCallback);
    glfwSetErrorCallback(glfw_error);
    glfwMakeContextCurrent(window);
    glClearColor(0,0,0,1);

    // Call the app init before the update loop begins
    app->init();

    resize(window);

    glfwSetWindowSizeCallback(window, glfw_resizeCallback);

    while(!glfwWindowShouldClose(window)) {
        app->tick();
        glfwSwapBuffers( window );
        glfwPollEvents();
    }

    app->shutdown();

    glfwTerminate();
    printf("Goodbye World\n");

    return 0;
    
}

unsigned long Platform::timeInMilliseconds() {
    static timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (t.tv_sec * 1000) + (t.tv_nsec / 1000000);
}