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
        Texture(std::string filename);
        ~Texture();
        void upload();

        GLuint getTextureId();
        int getWidth();
        int getHeight();

    private:
        GLuint _textureId;
        std::string _filename;
        bool _isUploaded;
        int _width, _height, _channels, _originalChannels;
        unsigned char* _imageData;
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