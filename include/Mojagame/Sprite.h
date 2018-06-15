#ifndef MOJAGAME_DISPLAY_SPRITE_H
#define MOJAGAME_DISPLAY_SPRITE_H

/**
 * A sprite is the base visual object. It has a render function and a transform.
 **/
class Sprite {
    public:
        Sprite();
        virtual ~Sprite();
        virtual void render( RenderContext* context );

        // Getters
        Transform* getTransform();
        Renderable* getRenderable();
        void setRenderable(Renderable* renderable);
        
    private:
        Transform* _transform;
        Renderable* _renderable;
};

#endif