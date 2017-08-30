#ifndef MOJAGAME_TYPES_H
#define MOJAGAME_TYPES_H

#include <functional>
#include <vector>
#include <list>

// Base
class App;
struct AppConfig;
class Component;
class Entity;
class Factory;
class Generator;
class GameEngine;
class Scene;

// Grapevine
class Grapevine;
class GrapevineListenerAttachment;
typedef std::function<bool(int,void*)> GrapevineListener;
typedef std::vector<GrapevineListenerAttachment*> GrapevineListenerAttachmentList;

// Math
class Mat4;
class Mat3;
class Vec4;
class Vec3;
class Vec2;

// Util
class Colour;

// native
class Platform;
class RenderContext;

// GL
class GLRenderContext;
class GLShader;
class GLTexture;

// Component
class Transform;
typedef std::list<Transform*>TransformChildList;
class Renderer;
class QuadRenderer;

enum SystemMessage {
    Close = 1,
    Update,
    Render,
    PostRender,
    AddedToScene,
    RemovedFromScene
};

enum Colours {
    White = 0xFFFFFFFF,
    Black = 0xFF000000,
    Blue = 0xFF0000FF,
    Red = 0xFFFF0000,
    Green = 0xFF00FF00
};

enum RenderFlags {
    Colour = 1,
    Texture = 2
};


#endif