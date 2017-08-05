#ifndef MOJAGAME_RENDERER_H
#define MOJAGAME_RENDERER_H

#include <cstdio>
#include <string>

#include <Mojagame/App.h>
#include <Mojagame/assets/MeshLoader.h>
#include <Mojagame/math/Matrix.h>

class Renderer {

    public:
        void render( MeshLoader* loader );
        void init( GLFWwindow* window );

    private:
        GLuint _program;
        GLuint _vertexBuffer;
        GLuint _indexBuffer;

        Mat4 _cameraProjection;
        Mat4 _cameraPosition;

        GLuint _compileShader( const char* src, GLint length, GLenum type );
};

#endif