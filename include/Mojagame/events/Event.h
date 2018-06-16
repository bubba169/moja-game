#pragma once

enum EventType {
    Resize = 0
};

struct Event {
    Event(int type) : type(type) {};
    virtual ~Event() {}

    int type;
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