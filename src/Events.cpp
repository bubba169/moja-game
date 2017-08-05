#include <Mojagame/Events.h>

/**
 * Event Dispatcher
 */

EventDispatcher::EventDispatcher() : _isDispatching(false) {
}

void EventDispatcher::dispatch( Event* event ) {
    bool cancelled(0);

    // Set the flag so the array is not changed while dispatching
    _isDispatching = true;

    for( std::vector<EventListener*>::iterator i(_listeners.begin()); !cancelled && (i != _listeners.end()); ++i ) {

        if (_removedListeners.size() > 0 && std::find(_removedListeners.begin(), _removedListeners.end(), *i) != _listeners.end()) {
            // This listener has been removed;
            continue;
        }

        cancelled = (*i)->onEvent( event );
    }

    _isDispatching = false;

    // Remove any listeners that were removed during dispatching
    if ( _removedListeners.size() ) {
        for ( auto i = _removedListeners.begin(); i != _removedListeners.end(); ++i) {
            _removeListener( *i );
        };
    }
    _removedListeners.clear();
}

void EventDispatcher::subscribe(EventListener* listener) {
    _listeners.push_back( listener );
}

void EventDispatcher::unsubscribe(EventListener* listener) {
    if ( !_isDispatching ) {
        _removeListener( listener );
    } else {
        _removedListeners.push_back( listener );
    }
}

void EventDispatcher::_removeListener(EventListener* listener) {
    _listeners.erase(std::remove_if(_listeners.begin(), _listeners.end(), [listener](EventListener* i) {
        return i == listener;
    }), _listeners.end());
}


/**
 * Event
 */

Event::Event( int type, void* target ) : _type(type), _target(target) {}
Event::Event( int type, void* target, void* data ) : _type(type), _target(target), _data(data) {}

int Event::getType() {
    return _type;
}

void* Event::getTarget() {
    return _target;
}

void* Event::getData() {
    return _data;
}

double Event::getDataDouble() {
    return *((double*)_data);
}