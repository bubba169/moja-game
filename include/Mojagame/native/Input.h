#ifndef MOJAGAME_APP_INPUT_H
#define MOJAGAME_APP_INPUT_H

#include <Mojagame/Events.h>

class Input : public EventDispatcher{

    public:
        onMouseDown( int x, int y );
        onMouseUp( int x, int y );

    protected:


};

#endif