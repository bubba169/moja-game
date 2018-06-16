#pragma once

class IEventListener {
    public:
        virtual bool onEvent(Event* event) = 0;
};