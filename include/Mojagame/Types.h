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

const int SYSTEM_MESSAGE_CLOSE = 1;
const int SYSTEM_MESSAGE_UPDATE = 2;
const int SYSTEM_MESSAGE_RENDER = 3;
const int SYSTEM_MESSAGE_POST_RENDER = 4;

const unsigned int COLOUR_WHITE = 0xFFFFFFFF;
const unsigned int COLOUR_BLACK = 0xFF000000;
const unsigned int COLOUR_BLUE = 0xFF0000FF;
const unsigned int COLOUR_GREEN = 0xFF00FF00;
const unsigned int COLOUR_RED = 0xFFFF0000;

const int RENDER_FLAG_COLOUR = 1;
const int RENDER_FLAG_TEXTURE = 2;

#endif