#include <Mojagame/App.h>
#include <Mojagame/native/Platform.h>
#include <Mojagame/native/GLFW.h>
#include <cstdio>

#ifdef MG_POSIX 
    #include <sys/time.h>
#endif

void glfw_error(int i, const char* error) {
    printf("ERROR: %i %s\n", i, error);
}

void glfw_framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    App::current()->resize(width, height);
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
    glfwSetErrorCallback(glfw_error);
    glfwMakeContextCurrent(window);
    glClearColor(0,0,0,1);

    // Call the app init before the update loop begins
    app->init();

    int currentWidth, currentHeight;

    glfwGetFramebufferSize(window, &currentWidth, &currentHeight);
    app->resize( currentWidth, currentHeight );

    glfwSetFramebufferSizeCallback(window, glfw_framebufferSizeCallback);

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
    #ifdef MG_POSIX
        timeval time;
        gettimeofday(&time, NULL);
        return time.tv_usec / 1000;
    #else
        return 0;
    #endif
}