#include <Mojagame/Factory.h>
#include <Mojagame/App.h>
#include <Mojagame/Entity.h>
#include <Mojagame/component/Transform.h>

Factory::Factory( App* app ) : _app(app) {}

Entity* Factory::create( int entityType ) 
{
    Entity* entity = new Entity(_app);

    entity->add( new Transform() );

    generate( entityType, entity );
    return entity;
}

void Factory::generate( int entityType, Entity* entity ) 
{
    std::map<int, Generator*>::iterator generator = _generators.find(entityType);
    if (generator != _generators.end()) {
        generator->second->generate( entity );
    }
}

void Factory::registerGenerator( int entityType, Generator* generator ) 
{
    _generators[entityType] = generator;
}