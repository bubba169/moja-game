#include <Mojagame/component/renderer/Renderer.h>
#include <Mojagame/native/RenderContext.h>
#include <Mojagame/Entity.h>
#include <Mojagame/Grapevine.h>

void Renderer::onAdded( Entity* entity ) {
    Component::onAdded(entity);
    _renderListenerId = _entity->getGrapevine()->listen( SystemMessage::Render, std::bind(&Renderer::_onRenderMessage, this, std::placeholders::_1, std::placeholders::_2) );
}

void Renderer::onRemoved() {
    _entity->getGrapevine()->detach( _renderListenerId );
    Component::onRemoved();
}

bool Renderer::_onRenderMessage( int message, void* data ) {
    render((RenderContext*)data);
    return true;
}