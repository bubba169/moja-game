#ifndef MOJAGAME_EVENTS_H
#define MOJAGAME_EVENTS_H

#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

/**
 * MOJAGAME GRAPEVINE
 * 
 * This is a messaging system where an object can provide a grapevine for other objects to listen for messages.
 * It is an impplementation of the observer pattern. Messages do not have any intended recipient but they do know 
 * their sender and can carry packets of data.
 * 
 * Listeners are added by attaching them to the grapevine.
 */

// Todo: Move this
enum SystemMessage {
    Close = 1,
    Update,
    PreRender,
    PostRender
};

// Abstract class to enable listening
// Has no properties of it's own, is only used for member function pointers
class GrapevineListener {};
class GrapevineListenerAttachment;
typedef bool (GrapevineListener::*GrapevineListenerCallback)(int, void*);
typedef std::vector<GrapevineListenerAttachment*> GrapevineListenerAttachmentList;

class GrapevineListenerAttachment {
    public:
        const int id;

        GrapevineListenerAttachment( GrapevineListener* listener, GrapevineListenerCallback callback, int message, int id );
        bool notify( int message, void* data );
        bool shouldNotify( int message );

        bool wasDetached();
        void detach();

    protected:
        GrapevineListener* _listener;
        GrapevineListenerCallback _callback;
        bool _wasDetached;
        int _message;

};

class Grapevine {
    public:
        Grapevine();
        void send( int message );
        void send( int message, void* data );
        int listen( GrapevineListener* listener, GrapevineListenerCallback callback, int message );
        int listen( GrapevineListener* listener, GrapevineListenerCallback callback );
        void detach( int id );
        void prune();
    protected:
        GrapevineListenerAttachmentList _listeners;
        int _idCounter;
};

#endif