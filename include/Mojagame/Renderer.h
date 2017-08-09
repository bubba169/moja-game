#ifndef MOJAGAME_RENDERER_H
#define MOJAGAME_RENDERER_H

#include <cstdio>
#include <vector>

#include <Mojagame/Entity.h>
#include <Mojagame/math/Matrix.h>

/**
 * Builds a list of entities as it receives RendererAdded events. Entities are placed in the list depending on their current parent
 * Calls a Render event on every entity in turn which can be picked up by a RendererComponent or ignored.
 */

class Renderer {

    public:

        void render();

    protected:
    
        std::vector<Entity*> _renderList;
};

#endif