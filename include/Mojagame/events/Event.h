#pragma once

class Sprite;

enum EventType {
    Resize = 0,
    KeyDown,
    KeyUp,
    PointerDown,
    PointerUp,
    PointerMove
};

struct Event {
    Event(int type) : type(type) {};
    virtual ~Event() {}

    int type;
    Sprite* target;
};

struct ResizeEvent : public Event {
    ResizeEvent(int width, int height, float pixelRatio) : 
        Event(EventType::Resize), 
        width(width),
        height(height),
        pixelRatio(pixelRatio) {}
    
    int width, height;
    float pixelRatio;
};

struct KeyEvent : public Event {
    KeyEvent(int type, int key, int mods) : 
        Event(type), 
        key(key),
        mods(mods) {}
    
    int key, mods;
};

enum PointerButton {
    None = -1,
    Left,
    Right,
    Middle
};
struct PointerEvent : public Event {
    PointerEvent(int type, int pointerId, int x, int y) : 
        Event(type), 
        pointerId(pointerId),
        x(x),
        y(y),
        button(PointerButton::None) {}

    PointerEvent(int type, int pointerId, int x, int y, int button) : 
        Event(type), 
        pointerId(pointerId),
        x(x),
        y(y),
        button(button) {}
    
    int x, y, pointerId, button;
};