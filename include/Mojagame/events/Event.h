#pragma once

class Sprite;

enum EventType {
    Resize = 0
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