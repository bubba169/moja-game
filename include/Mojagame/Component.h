#ifndef MOJAGAME_COMPONENT_H
#define MOJAGAME_COMPONENT_H

#include <string>

class Component {

    public:
        Entity* getEntity();
        App* getApp();

    protected:
        Entity* entity;

};

#endif