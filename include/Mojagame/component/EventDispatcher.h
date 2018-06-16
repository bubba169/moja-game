#pragma once

struct EventDispatcherAttachment {
    IEventListener* listener;
    int priority;

    EventDispatcherAttachment(IEventListener* listener, int priority) :
        listener(listener),
        priority(priority) {}
};

class Component;

class EventDispatcher : public Component {
    public:
        EventDispatcher(Sprite* sprite);
        void attach(IEventListener* listener, int priority = 0);
        void detach(IEventListener* listener);
        void dispatch(Event* event);

    private:
        std::list<EventDispatcherAttachment> __listeners;
        bool __dispatching;
};