#include <Mojagame.h>

EventDispatcher::EventDispatcher() : __dispatching(false) {}

void EventDispatcher::attach(IEventListener* listener, int priority) {
    EventDispatcherAttachment attachment(listener, priority);
    __listeners.insert( 
        std::find_if( __listeners.begin(), __listeners.end(), [priority] (EventDispatcherAttachment attachment) {
            if (attachment.priority > priority) {
                return true;
            }
            return false;
        }),
        attachment
    );
}

void EventDispatcher::detach(IEventListener* listener) {
    __listeners.erase(
        std::remove_if(__listeners.begin(), __listeners.end(), [listener](EventDispatcherAttachment attachment) {
            return (attachment.listener == listener);
        }),
        __listeners.end()
    );
}

void EventDispatcher::dispatch(Event* event) {
    // Breaks the list on the 
    std::find_if_not(__listeners.begin(), __listeners.end(), [event](EventDispatcherAttachment attachment) {
        return attachment.listener->onEvent(event);
    });
}