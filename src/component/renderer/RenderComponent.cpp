#include <Mojagame/component/renderer/RenderComponent.h>
#include <Mojagame/Renderer.h>
#include <Mojagame/Entity.h>
#include <Mojagame/Grapevine.h>

void RenderComponent::onAdded( Entity* entity ) {
    Component::onAdded(entity);
    _renderListenerId = _entity->getGrapevine()->listen( SYSTEM_MESSAGE_RENDER, std::bind(&RenderComponent::_onRenderMessage, this, std::placeholders::_1, std::placeholders::_2) );
}

void RenderComponent::onRemoved() {
    _entity->getGrapevine()->detach( _renderListenerId );
    Component::onRemoved();
}

bool RenderComponent::_onRenderMessage( int message, void* data ) {
    render((RenderContext*)data);
    return true;
}