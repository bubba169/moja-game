#include <Mojagame/Grapevine.h>

/**
 * Grapevine
 */

Grapevine::Grapevine() : _idCounter(0) {}

/**
 * Send the messages to the listeners
 */
void Grapevine::send( int message ) {
    send( message, NULL );
}

void Grapevine::send( int message, void* data ) {

    std::find_if_not( _listeners.begin(), _listeners.end(), [message, data](GrapevineListenerAttachment* attachment) {
        if ( attachment->shouldNotify( message ) ) {
            // Listener will return false to cancel the event
            return attachment->notify( message, data );
        }
        return true;
    });

    prune();
}

int Grapevine::listen( GrapevineListener* listener, GrapevineListenerCallback callback ) {
    listen( listener, callback, 0 );
}

int Grapevine::listen( GrapevineListener* listener, GrapevineListenerCallback callback, int message ) {
    GrapevineListenerAttachment* attachment = new GrapevineListenerAttachment( listener, callback, message, _idCounter++ );
    _listeners.push_back( attachment );
    return attachment->id;
}

void Grapevine::detach( int id ) {
    std::find_if( _listeners.begin(), _listeners.end(), [id](GrapevineListenerAttachment* attachment) {
        if (attachment->id == id) {
            // This marks the attachment as detached so it can be pruned later
            attachment->detach();

            // Finished searching now break the loop
            return true;
        }
        return false;
    });
}

void Grapevine::prune() {
    _listeners.erase(
        std::remove_if(
            _listeners.begin(), _listeners.end(), [](GrapevineListenerAttachment* attachment) {
                if ( attachment->wasDetached() ) {
                    delete attachment;
                    return true;
                }

                return false;
            }
        ),
    _listeners.end());
}

/**
 * GrapevineListenerAttachment
 */

GrapevineListenerAttachment::GrapevineListenerAttachment( GrapevineListener* listener, GrapevineListenerCallback callback, int message, int id ):
    _listener(listener),
    _callback(callback),
    _message(message),
    id(id) 
{}

bool GrapevineListenerAttachment::shouldNotify( int message ) {
    return !_wasDetached && ( message == 0 || message == _message);
}

bool GrapevineListenerAttachment::notify( int message, void* data ) {
    return (_listener->*_callback)(message, data);
}

bool GrapevineListenerAttachment::wasDetached() {
    return _wasDetached;
}

void GrapevineListenerAttachment::detach() {
    _wasDetached = true;
}