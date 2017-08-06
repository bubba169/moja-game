#include <Mojagame/native/platform/GLFWPlatform.h>

int Platform::run( App* app ) {

    GLFWwindow* window;

    if (!glfwInit()) return -1;

    window = glfwCreateWindow( app->config->windowWidth, app->config->windowHeight, app->config->title, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)) {

        app->update();
        
        glfwSwapBuffers( window );
        glfwPollEvents();
    }

    glfwTerminate();
    printf("Goodbye World\n");

    return 0;
    
}

unsigned long Platform::timeInMilliseconds() {
    #if defined(LINUX) || defined(MAC)
        timeval time;
        gettimeofday(&time, NULL);
        return time.tv_usec / 1000;
    #else
        return 0;
    #endif
}