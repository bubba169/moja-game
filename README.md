# MoJaGame
MoJaWorks Game Framework

## Concepts

MoJaGame is based on a few key concepts outline below.

### Grapevine
Grapevine is an implementation of the observer pattern. As an application grows it can become difficult to pass information between objects without each knowing of the other's existance. Grapevine gets around this issue by breaking dependancies between classes. The object being observed broadcasts a message along the grapevine and any object listening for that message on the same vine will receive it. It is included via composition so the observed object will have a grapevine instance that observers can attach to.

#### Listening

Objects can be listen for just one message at a time or to any message that comes down the vine. 

`Grapevine::listen( int message, GrapeVineListener listener, int priority = 100 )`<br>
`Grapevine::listen( GrapeVineListener listener, int priority = 100 )`

A given listener function will be called for any matching message. This should have the signature:

`bool listenerFunction( int message, void* data )`

If passing a member function, the first parameter of the listener function must be bound to the observing instance e.g.:

`grapevine.listen( std::bind( &MyClass::onMessage, this, std::placeholder::_1, std::placeholder::_2) );`

#### Halting the message
If the message is to continue along the grapevine, the listener function must return `true`. Returning `false` will prevent the message going any further.

#### Priority
By default all messages are added with a priority of `100`. This can be altered by passing the `priority` parameter to the `Grapevine::listen` function. Listeners with a higher priority will be called first giving them the chance cancel the message before it is passed to the lesser priority listeners.
