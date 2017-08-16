#ifndef MOJAGAME_COMPONENT_H
#define MOJAGAME_COMPONENT_H

#include <Mojagame/Types.h>
#include <string>

class Component {

    public:
        Component();
        virtual ~Component() {};

        // Getters
        Entity* getEntity();
        App* getApp();
        int getType();
        bool getIsRemoved();
        virtual std::string getName() = 0;

        // Events
        virtual void onAdded( Entity* entity );
        virtual void onRemoved();

    protected:
        Entity* _entity;
        int _type;

};

#endif