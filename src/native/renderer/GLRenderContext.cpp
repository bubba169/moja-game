void Renderer::init( ) {
    // Set up the basics
    glClearColor(0, 0, 0, 1);
    glEnable( GL_DEPTH_TEST );

    // Set up some basic shaders
    std::string vsSrc("");
    vsSrc += "uniform mat4 uProjection;";
    vsSrc += "uniform mat4 uView;";
    vsSrc += "attribute vec3 aPosition;";
    vsSrc += "void main() {";
    vsSrc += "  gl_Position = uProjection * uView * vec4(aPosition, 1);";
    vsSrc += "}";

    GLuint vs = _compileShader( vsSrc.c_str(), vsSrc.length(), GL_VERTEX_SHADER );
    printf("Compiled vertex shader: %d\n", vs);

    std::string fsSrc("");
    fsSrc += "void main() {";
    fsSrc += "  gl_FragColor = vec4(0,0,1,1);";
    fsSrc += "}";

    GLuint fs = _compileShader( fsSrc.c_str(), fsSrc.length(), GL_FRAGMENT_SHADER );
    printf("Compiled fragment shader: %d\n", fs);

    _program = glCreateProgram();
    glAttachShader( _program, vs );
    glAttachShader( _program, fs );
    glLinkProgram( _program );

    GLint result;
    glGetProgramiv( _program, GL_LINK_STATUS, &result);

    if ( !result ) {
        GLchar info[250];
        GLint infoLength;
        glGetProgramInfoLog( _program, 250, &infoLength, info );
        printf( "%s\n", info );
        return;
    }

    printf("Compiled shader program: %d\n", _program);

    glGenBuffers( 1, &_vertexBuffer );
    glGenBuffers( 1, &_indexBuffer );

    int width, height;
    glfwGetWindowSize( window, &width, &height );
    glViewport( 0, 0, width, height );


    float near(1), far(5000), fov(120), top(tan(fov*0.5)*near), right(top), left(-right), bottom(-top);
    float camElements[] = {
        (2*near)/(right-left), 0, (right+left)/(right-left), 0,
        0, (2*near)/(top-bottom), (top+bottom)/(top-bottom), 0,
        0, 0, -(far+near)/(far-near), (-2*far*near)/(far-near),
        0, 0, -1, 0
    };
    _cameraProjection.copyFrom( camElements );
    _cameraPosition.translate( 0, 0, 10)->inverse();

    _cameraPosition.print();
}

void Renderer::render( MeshLoader* loader ) {

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glBindBuffer( GL_ARRAY_BUFFER, _vertexBuffer );
    glBufferData( GL_ARRAY_BUFFER, loader->vertices.size() * 4, (void*)&loader->vertices[0], GL_STREAM_DRAW );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _indexBuffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, loader->indexes.size() * 2, (void*)&loader->indexes[0], GL_STREAM_DRAW );

    glUseProgram( _program );

    GLuint projection = glGetUniformLocation( _program, "uProjection" );
    glUniformMatrix4fv( projection, 1, false, _cameraProjection.getData() );

    GLuint uView = glGetUniformLocation( _program, "uView" );
    glUniformMatrix4fv( uView, 1, true, _cameraPosition.getData() );

    GLuint position = glGetAttribLocation( _program, "aPosition" );
    glEnableVertexAttribArray( position );
    glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 17*4, 0);

    glDrawElements( GL_TRIANGLES, loader->indexes.size(), GL_UNSIGNED_SHORT, 0 );

    int error( glGetError() );
    if ( error ) {
        printf( "GLError: %d\n", error );
    }

}


/**
 * Private
 */

GLuint Renderer::_compileShader( const char* src, GLint length, GLenum type ) {
    GLuint shader( glCreateShader(type) );
    glShaderSource( shader, 1, &src, &length );
    glCompileShader( shader ); 

    GLint result;
    glGetShaderiv( shader, GL_COMPILE_STATUS, &result);

    if ( !result ) {
        GLchar info[250];
        GLint infoLength;
        glGetShaderInfoLog( shader, 250, &infoLength, info );
        printf( "%s\n", info );
        return 0;
    }

    return shader;
}