#pragma once

// Std libraries
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <list>
#include <functional>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <stb_image.h>

#ifdef MG_DESKTOP
    #include <Mojagame/native/GLFW.h>
    #include <ctime>
#endif

#include <Mojagame/events/Event.h>
#include <Mojagame/events/IEventListener.h>

#include <Mojagame/InputMap.h>

#include <Mojagame/math/Matrix.h>
#include <Mojagame/math/Vector.h>

#include <Mojagame/renderer/RenderContext.h>
#include <Mojagame/renderer/Shader.h>
#include <Mojagame/renderer/Texture.h>

#include <Mojagame/App.h>
#include <Mojagame/Sprite.h>
#include <Mojagame/component/Component.h>
#include <Mojagame/Scene.h>

#include <Mojagame/native/Platform.h>

#include <Mojagame/util/Bundle.h>
#include <Mojagame/util/Colour.h>

#include <Mojagame/component/EventDispatcher.h>
#include <Mojagame/component/renderable/Renderable.h>
#include <Mojagame/component/renderable/Quad.h>
#include <Mojagame/component/renderable/Image.h>

#include <Mojagame/component/Transform.h>
#include <Mojagame/component/renderable/Quad.h>