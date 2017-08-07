#include <Mojagame/Grapevine.h>

/**
 * Grapevine
 */

Grapevine::Grapevine() : _idCounter(0) {}

Grapevine::~Grapevine() {
    // Make sure to delete all of the attachments from the heap
    std::for_each( _listeners.begin(), _listeners.end(), [](GrapevineListenerAttachment* attachment) {
        delete attachment;
    });
}

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

/**
 * Listen for messages
 */
int Grapevine::listen( GrapevineListener listener, int priority ) {
    return listen( 0, listener, priority );
}

int Grapevine::listen( int message, GrapevineListener listener, int priority ) {
    // Creat an attachment
    GrapevineListenerAttachment* attachment = new GrapevineListenerAttachment( listener, message, _idCounter++, priority );

    // Insert it based on priority. It will be placed before any listener that has a priority less than it's own
    _listeners.insert( 
        std::find_if( _listeners.begin(), _listeners.end(), [priority](GrapevineListenerAttachment* existing) {
            if ( existing->getPriority() < priority ) {
                return true;
            }
            return false;
        }),
        attachment
    );

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

GrapevineListenerAttachment::GrapevineListenerAttachment( GrapevineListener listener, int message, int id, int priority ):
    _listener(listener),
    _message(message),
    _priority(priority),
    id(id) 
{}

bool GrapevineListenerAttachment::shouldNotify( int message ) {
    return !_wasDetached && ( message == 0 || message == _message);
}

bool GrapevineListenerAttachment::notify( int message, void* data ) {
    return _listener(message, data);
}

bool GrapevineListenerAttachment::wasDetached() {
    return _wasDetached;
}

int GrapevineListenerAttachment::getPriority() {
    return _priority;
}

void GrapevineListenerAttachment::detach() {
    _wasDetached = true;
}