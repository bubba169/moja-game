#ifndef MOJAGAME_EVENTS_H
#define MOJAGAME_EVENTS_H

#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <functional>

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

class GrapevineListenerAttachment;
typedef std::function<bool(int,void*)> GrapevineListener;
typedef std::vector<GrapevineListenerAttachment*> GrapevineListenerAttachmentList;

class GrapevineListenerAttachment {
    public:
        const int id;

        GrapevineListenerAttachment( GrapevineListener listener, int message, int id );
        bool notify( int message, void* data );
        bool shouldNotify( int message );

        bool wasDetached();
        void detach();

    protected:
        GrapevineListener _listener;
        bool _wasDetached;
        int _message;

};

class Grapevine {
    public:
        Grapevine();
        void send( int message );
        void send( int message, void* data );
        int listen( int message, GrapevineListener listener );
        int listen( GrapevineListener listener );
        void detach( int id );
        void prune();
    protected:
        GrapevineListenerAttachmentList _listeners;
        int _idCounter;
};

#endif