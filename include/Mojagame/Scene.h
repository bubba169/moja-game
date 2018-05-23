#ifndef MOJAGAME_SCENE_H
#define MOJAGAME_SCENE_H

class TextureManager {
    public:
        int read(const char* filename);
        void upload(int textureId);

    private:
        std::vector<Texture*> _textures;
};

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

    protected:
        RenderContext* _context;
        float _stageWidth, _stageHeight, _marginLeft, _marginTop;

};

#endif