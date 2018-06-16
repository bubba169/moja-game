#pragma once

class EventDispatcher;

class Scene : public Sprite {

    public:
        Scene();
        virtual ~Scene();

        void resize( float width, float height, float pixelRatio );
        void init( float stageWidth, float stageHeight );
        void render();

        // Dimensions relative to stage
        float getTotalWidth();
        float getTotalHeight();
        float getStageWidth();
        float getStageHeight();
        float getMarginLeft();
        float getMarginTop();
        float getLeft();
        float getRight();
        float getTop();
        float getBottom();

        RenderContext* getRenderContext();
        EventDispatcher* getEventDispatcher();

    private:
        RenderContext* __context;
        float __stageWidth, __stageHeight, __marginLeft, __marginTop;
        EventDispatcher* __eventDispatcher;
};