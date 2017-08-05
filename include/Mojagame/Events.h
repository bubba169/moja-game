#ifndef MOJAGAME_EVENTS_H
#define MOJAGAME_EVENTS_H

#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

enum EventType {
    Close = 0,
    Update,
    PreRender,
    PostRender
};

/**
 * Event listener is a functor that has a pointer to the listener
 */

class Event {
    public:
        Event( int type, void* target );
        Event( int type, void* target, void* data );

        void* getData();
        double getDataDouble();
        void* getTarget();
        int getType();

    protected:
        void* _data;
        void* _target;
        int _type;
};

class EventListener {
    public:
        virtual bool onEvent( Event* event ) = 0;
};

class EventDispatcher {
    public:
        EventDispatcher();
        void dispatch( Event* event );
        void subscribe( EventListener* listener );
        void unsubscribe( EventListener* listener );
    protected:
        void _removeListener(EventListener* listener);

        std::vector<EventListener*> _listeners;
        std::vector<EventListener*> _removedListeners;
        bool _isDispatching;
};



#endif