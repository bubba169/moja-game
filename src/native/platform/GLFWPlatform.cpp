#include <Mojagame/App.h>
#include <Mojagame/native/Platform.h>
#include <Mojagame/native/GLFW.h>
#include <cstdio>

#ifdef MG_POSIX 
    #include <sys/time.h>
#endif

void onError(int i, const char* error) {
    printf("ERROR: %i %s\n", i, error);
}

int Platform::run( App* app ) {

    GLFWwindow* window;

    if (!glfwInit()) return -1;

    AppConfig* config = app->getConfig();

    window = glfwCreateWindow( config->windowWidth, config->windowHeight, config->title, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwSetErrorCallback(onError);

    glfwMakeContextCurrent(window);
    glClearColor(0,0,0,1);

    app->init();

    while(!glfwWindowShouldClose(window)) {

        app->update();

        glClear( GL_COLOR_BUFFER_BIT );

        app->render();
        
        glfwSwapBuffers( window );
        glfwPollEvents();
    }

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