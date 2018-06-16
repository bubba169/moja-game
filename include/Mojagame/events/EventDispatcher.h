#pragma once

struct EventDispatcherAttachment {
    IEventListener* listener;
    int priority;

    EventDispatcherAttachment(IEventListener* listener, int priority) :
        listener(listener),
        priority(priority) {}
};

class EventDispatcher {
    public:
        EventDispatcher();
        void attach(IEventListener* listener, int priority = 0);
        void detach(IEventListener* listener);
        void dispatch(Event* event);

    private:
        std::list<EventDispatcherAttachment> __listeners;
        bool __dispatching;
};