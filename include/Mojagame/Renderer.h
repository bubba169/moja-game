#ifndef MOJAGAME_RENDERER_H
#define MOJAGAME_RENDERER_H

class Shader {
    public:
        Shader( std::string vertexSrc, std::string fragmentSrc );
        GLuint getProgram();
        bool upload();
    protected:
        std::string _vertexSrc;
        std::string _fragmentSrc;
        GLuint _program;

        GLuint _compileShader( const char* src, GLint length, GLuint type );
};

class Texture {
    // GL texture stuff
    public:
        Texture(const char* filename);
        GLuint getTextureId();
        void upload(void* bytes, int length);

    private:
        GLuint _textureId;
        const char* _filename;
        bool _isUploaded;
};

class RenderContext {

    public:
        RenderContext();

        void clear();

        void init();
        void resize( int width, int height );

        // Flush any existing draw calls if using batch drawing
        void flush();

        // This is the basic call all others use.
        void drawTriangles( std::vector<float>* vertices, std::vector<unsigned short>* indexes, int shaderId, Mat3* transform, int* textureIds = NULL, int numTextures = 0 );

        // The following functions will upload a texture and keep the textureId current across context updates
        int uploadTexture( Texture* texture );
        int uploadShader( Shader* shader );

    protected:

        GLuint _vertexBuffer, _indexBuffer;

        std::vector<Shader*> _shaders;
        std::vector<Texture*> _textures;

        Mat4 _projection;

        void _initShaders();
        
};

#endif