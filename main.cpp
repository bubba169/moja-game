#include <cstdio>
#include "GLFW/glfw3.h"

int points[] = {100, 100, 200, 100, 150, 200};
unsigned int vbo;

void initGl() {
    glGenBuffers( 1, &vbo );
    glViewport( 0, 600, 800, 600 );
}

void render() {
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 6 * 4, points, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main() {
    printf("Hello World\n");

    if (glfwInit() == GLFW_FALSE) {
        printf("GLFW Initialisation failed");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow( 800, 600, "Hello", NULL, NULL);

    if ( window == NULL ) {
        printf("Could not create window\n");
        glfwTerminate();
        return -2;
    }else {
        printf("Window created\n");
    }

    glfwMakeContextCurrent(window);
    glClearColor(0, 0, 0, 1);

    initGl();

    while( !glfwWindowShouldClose(window) ) {
        glClear( GL_COLOR_BUFFER_BIT );

        render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    printf("Goodbye\n");
    glfwTerminate();

}