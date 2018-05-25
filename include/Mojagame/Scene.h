#ifndef MOJAGAME_SCENE_H
#define MOJAGAME_SCENE_H

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

        // Textures
        void loadTexture(std::string filename);
        void freeTexture(std::string filename);
        void getTextureDimensions(std::string filename, int* width, int* height);
        bool textureLoaded(std::string filename);

    protected:
        RenderContext* _context;
        float _stageWidth, _stageHeight, _marginLeft, _marginTop;
        std::map<std::string, Texture*> _textures;
};

#endif