#include <Mojagame/component/renderer/QuadRenderer.h>

std::string QuadRenderer::getName() {
    return "QuadRenderer";
}

void QuadRenderer::render( RenderContext* context ) {
    printf("Rendering\n");
}