#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED

#include <Mojagame/App.h>
#include <Mojagame/Entity.h>
#include <map>

/**
 * Factories work by first being assigned generators to handle creating entities with given
 * properties. Then the factory can be called on to provide an Entity by specifying the generator
 * name
 */

class App;
class Entity;

class Generator {
    public:
        virtual void generate(Entity* entity) = 0; 
};

class Factory {

    public:
        Factory(App*);
        Entity* create( int entityType );
        void registerGenerator( int entityType, Generator* generator );

    protected:
        App* _app;
        std::map<int, Generator*> _generators;
};

#endif