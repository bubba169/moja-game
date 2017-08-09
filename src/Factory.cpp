#include <Mojagame/Factory.h>

Factory::Factory( App* app ) : _app(app) {}

Entity* Factory::create( int entityType ) 
{
    Entity* entity = new Entity(_app);
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