#ifndef MOJAGAME_COMPONENT_H
#define MOJAGAME_COMPONENT_H

#include <string>
#include <Mojagame/Entity.h>
#include <Mojagame/App.h>

class Entity;
class App;

class Component {

    public:
        Component();

        // Getters
        Entity* getEntity();
        App* getApp();
        int getType();
        bool getIsRemoved();
        virtual std::string getName();

        // Events
        void onAdded( Entity* entity );
        void onRemoved();

    protected:
        Entity* _entity;
        int _type;
        bool _isRemoved;

};

#endif