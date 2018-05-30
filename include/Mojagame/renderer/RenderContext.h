#ifndef MOJAGAME_RENDER_CONTEXT_H
#define MOJAGAME_RENDER_CONTEXT_H

class RenderContext {

    public:
        RenderContext();
        ~RenderContext();

        void clear();

        void init();
        void resize( int width, int height );

        // Flush any existing draw calls if using batch drawing
        void flush();

        // This is the basic call all others use.
        void drawTriangles( std::vector<float>* vertices, std::vector<unsigned short>* indexes, int shaderId, Mat3* transform, std::vector<std::string>* textureFilenames = NULL);

        // The following functions will upload a texture and keep the textureId current across context updates
        int uploadTexture( Texture* texture );
        int uploadShader( Shader* shader );

        // Textures
        void loadTexture(std::string filename);
        void freeTexture(std::string filename);
        void getTextureDimensions(std::string filename, int* width, int* height);
        bool textureLoaded(std::string filename);

    protected:

        GLuint _vertexBuffer, _indexBuffer;

        std::vector<Shader*> _shaders;
        std::map<std::string, Texture*> _textures;

        Mat4 _projection;

        void _initShaders();
        
};

#endif