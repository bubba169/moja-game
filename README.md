# MoJaGame
MoJaWorks Game Framework

## Concepts

MoJaGame is based on a few key concepts outline below.

### The Game Engine
The game engine is a class that can be attached to the `App` for convenient access. It's main purpose will be to manage the flow of the game, construct the scene and contain game systems to manage the different elements in play.

### Grapevine
Grapevine is an implementation of the observer pattern. As an application grows it can become difficult to pass information between objects without each knowing of the other's existance. Grapevine gets around this issue by breaking dependancies between classes. The object being observed broadcasts a message along the grapevine and any object listening for that message on the same vine will receive it. It is included via composition so the observed object will have a grapevine instance that observers can attach to.

#### Listening

Objects can be listen for just one message at a time or to any message that comes down the vine. 

`Grapevine::listen( int message, GrapeVineListener listener, int priority = 100 )`<br>
`Grapevine::listen( GrapeVineListener listener, int priority = 100 )`

A given listener function will be called for any matching message. This should have the signature:

`bool listenerFunction( int message, void* data )`

If passing a member function, the first parameter of the listener function must be bound to the observing instance e.g.:

`grapevine.listen( std::bind( &MyClass::onMessage, this, std::placeholders::_1, std::placeholders::_2) );`

#### Halting the message
If the message is to continue along the grapevine, the listener function must return `true`. Returning `false` will prevent the message going any further.

#### Priority
By default all messages are added with a priority of `100`. This can be altered by passing the `priority` parameter to the `Grapevine::listen` function. Listeners with a higher priority will be called first giving them the chance cancel the message before it is passed to the lesser priority listeners.

### Entity / Component
MoJaGame is based on the entity component principal where generic entities that exist in a game are defined by the components they contain. Components do very little on their own, they are more like information storage but can contain code that should only affect the entity they are attached to. Components should not need to know about eachother - ff they expect to influence another component they should send a message over the grapevine.

#### Creating Entities
Entites are created by the factory. Generators can be registered with the factory to build Entities. A generator is a simple class that implements a single method: 

`generate( Entity* entity )`

The generator can modify the entity in the parameter to add components etc. Generators are added using 

`Factory::registerGenerator( int entityType, Generator* generator )`

and Entities are created using

`Factory::create( int entityType )`

The generator matching the entityType will be used to generate the Entity.

#### Reusing Generators
If an entity type is a specialised version of another type, it is possible to first create the base type and then add the extra components. To do this, the generator can make use of the following function:

`Factory::generate( int entityType, Entity* entity )`

This runs a generator on an existing entity. The factory can be accessed through the entity's `getApp()->getFactory()`. Generators can be set to call multiple other generators in this way allowing entities to be built up in stages.

#### Components
Components are what define individual entities. They are small parcels of functionality that can listen for messages on the grapevine and notify the entity with how it should react. Components are added to an Entity through the `Entity::add(Component* component)` funtion. Each component type has a name that is defined by overriding the `Component::getName()` function. This name can be used to find a component attached to an entity using `Entity::find(string name)`. It is also used to remove components using `Entity::remove(string name)`. When removing, a pointer to the removed component is returned. This should be freed if you are not expecting to use it any further.


