#include <Mojagame.h>

RenderContext::RenderContext() {
}

RenderContext::~RenderContext() {
    std::for_each(_textures.begin(), _textures.end(), [](std::pair<std::string, Texture*> val) {
        delete val.second;
    });
}

void RenderContext::init( ) {
    // Set up the basics
    glClearColor(0, 1, 0, 1);
    _initShaders();

    glGenBuffers( 1, &_vertexBuffer );
    glGenBuffers( 1, &_indexBuffer );

    printf("Buffers %i %i\n", _vertexBuffer, _indexBuffer);
}

void RenderContext::clear() {
    glClear( GL_COLOR_BUFFER_BIT );
}

void RenderContext::resize( int width, int height ) {
    glViewport( 0, 0, width, height );

    float sx = 1.0 / width; 
    float sy = 1.0 / -height;

    _projection.identity();
    _projection.set(1, 1, 2 * sx);
    _projection.set(2, 2, 2 * sy);
    _projection.set(4, 1, -1);
    _projection.set(4, 2, 1);
}

void RenderContext::flush() {
}

void RenderContext::drawTriangles( std::vector<float>* vertices, std::vector<unsigned short>* indexes, int shaderId, Mat3* transform, std::vector<std::string>* textureFilenames )
{
    glBindBuffer( GL_ARRAY_BUFFER, _vertexBuffer );
    glBufferData( GL_ARRAY_BUFFER, vertices->size() * sizeof(GLfloat), (void*)&(vertices->front()), GL_STREAM_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _indexBuffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, indexes->size() * 2, (void*)&(indexes->front()), GL_STREAM_DRAW );

    Shader* shader = _shaders.at(shaderId);
    glUseProgram( shader->getProgram() );

    if (textureFilenames) {
        for (int i = 0; i < textureFilenames->size(); i++) {
            GLuint uTexture = glGetUniformLocation(shader->getProgram(), (std::string("uTexture") + std::to_string(i)).c_str());
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, _textures.at(textureFilenames->at(i))->getTextureId());
            glUniform1i(uTexture, i);
        }
    }

    int offset = 0;
    std::for_each(shader->getAttributes()->begin(), shader->getAttributes()->end(), [&offset, shader](std::pair<std::string, int> attr) mutable {
        GLuint location = glGetAttribLocation( shader->getProgram(), attr.first.c_str() );
        glEnableVertexAttribArray( location );
        glVertexAttribPointer( location, attr.second, GL_FLOAT, GL_FALSE, shader->getVertexSize() * sizeof(GLfloat), (void*)(offset * sizeof(GLfloat)));
        offset += attr.second;
    });

    GLuint uProjection = glGetUniformLocation( shader->getProgram(), "uProjection");
    glUniformMatrix4fv( uProjection, 1, false, _projection.getData() );

    GLuint uTransform = glGetUniformLocation( shader->getProgram(), "uTransform");
    glUniformMatrix3fv( uTransform, 1, true, transform->getData() );

    glDrawElements( GL_TRIANGLES, indexes->size(), GL_UNSIGNED_SHORT, 0 );
    
    int error( glGetError() );
    if ( error ) {
        printf( "GLError: %d\n", error );
    }
}

int RenderContext::uploadShader( Shader* shader ) {
    shader->upload();
    _shaders.push_back(shader);
    return _shaders.size() - 1;
}

void RenderContext::_initShaders() {

    // Build the colour shader;
    std::string vsSrc("");
    vsSrc += "attribute vec2 aPosition;";
    vsSrc += "attribute vec4 aColour;";
    vsSrc += "varying vec4 vColour;";
    vsSrc += "uniform mat4 uProjection;";
    vsSrc += "uniform mat3 uTransform;";
    vsSrc += "void main() {";
    vsSrc += "  gl_Position = uProjection * vec4(uTransform * vec3(aPosition, 1), 1);";
    vsSrc += "  vColour = aColour;";
    vsSrc += "}";

    std::string fsSrc("");
    fsSrc += "varying vec4 vColour;";
    fsSrc += "void main() {";
    fsSrc += "  gl_FragColor = vColour;";
    fsSrc += "}";

    uploadShader(new Shader( vsSrc, fsSrc, 6, {
        {"aPosition", 2},
        {"aColour", 4}
    }));

    // Build the texture shader;
    vsSrc = "";
    vsSrc += "attribute vec2 aPosition;";
    vsSrc += "attribute vec2 aUV;";
    vsSrc += "attribute vec4 aColour;";

    vsSrc += "varying vec4 vColour;";
    vsSrc += "varying vec2 vUV;";

    vsSrc += "uniform mat4 uProjection;";
    vsSrc += "uniform mat3 uTransform;";

    vsSrc += "void main() {";
    vsSrc += "  gl_Position = uProjection * vec4(uTransform * vec3(aPosition, 1), 1);";
    vsSrc += "  vUV = aUV;";
    vsSrc += "  vColour = aColour;";
    vsSrc += "}";

    //--

    fsSrc = "";
    fsSrc += "varying vec4 vColour;";
    fsSrc += "varying vec2 vUV;";
    fsSrc += "uniform sampler2D uTexture0;";
    
    fsSrc += "void main() {";
    fsSrc += "  vec4 texColour = texture2D(uTexture0, vUV);";
    fsSrc += "  texColour.rgb = texColour.rgb * texColour.a;";
    fsSrc += "  gl_FragColor = vColour * texColour;";
    fsSrc += "}";

    uploadShader(new Shader( vsSrc, fsSrc, 8, {
        {"aPosition", 2},
        {"aUV", 2},
        {"aColour", 4}
    } ));
}

void RenderContext::loadTexture(std::string filename) {
    if (!textureLoaded(filename)) {
        Texture* texture = new Texture(filename);
        texture->upload();

        _textures[filename] = texture;
    } else {
        _textures[filename]->addUsage();
    }
}

void RenderContext::freeTexture(std::string filename) {
    if (textureLoaded(filename)) {
        int usage = _textures[filename]->freeUsage();
        if (usage == 0) {
            delete _textures[filename];
            _textures.erase(filename);
        }
    }
}

void RenderContext::getTextureDimensions(std::string filename, int* width, int* height) {
    if (textureLoaded(filename)) {
        Texture* texture = _textures[filename];
        *width = texture->getWidth();
        *height = texture->getHeight();
    } else {
        *width = 0;
        *height = 0;
    }
}

bool RenderContext::textureLoaded(std::string filename) {
    return _textures.find(filename) != _textures.end();
}