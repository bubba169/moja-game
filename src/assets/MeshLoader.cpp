#include <Mojagame/assets/MeshLoader.h>

MeshLoader::MeshLoader() : numVertices(0) {
}

unsigned int MeshLoader::load( const char* filename ) {
    
    std::map<std::string,int> indexLookup;
    std::vector<std::string> filenameParts;
    boost::split( filenameParts, filename, boost::is_any_of("/") );
    filenameParts.pop_back();
    std::string filepath = boost::join( filenameParts, "/");

    std::ifstream modelFile(filename);

    std::vector<Vec3*> tempVertices;
    std::vector<Vec3*> tempNormals;
    Material* currentMaterial;
   
    for( std::string line; std::getline( modelFile, line); ) {
        //printf( "%s\n", line.c_str() );

        std::vector<std::string> lineParts;
        boost::split( lineParts, line, boost::is_any_of(" ") );

        if( lineParts.at(0) == "mtllib" ) {
           _parseMaterialLib( (filepath + "/" + lineParts.at(1)).c_str() );
        }
        else if ( lineParts.at(0) == "v" ) {
            tempVertices.push_back( new Vec3( atof(lineParts.at(1).c_str()), atof(lineParts.at(2).c_str()), atof(lineParts.at(3).c_str()) ));
        }
        else if ( lineParts.at(0) == "vn" ) {
            tempNormals.push_back( new Vec3( atof(lineParts.at(1).c_str()), atof(lineParts.at(2).c_str()), atof(lineParts.at(3).c_str()) ));
        }
        else if ( lineParts.at(0) == "usemtl" ) {
            currentMaterial = _materials[ lineParts.at(1).c_str() ];
        }
        else if ( lineParts.at(0) == "f" ) {

            // This will be a triangle
            if ( lineParts.size() == 5 ) {
                lineParts.insert( lineParts.end() - 1, lineParts.at(3) );
                lineParts.insert( lineParts.end(), lineParts.at(1) );
            }

            for ( int i(1); i < lineParts.size(); ++i ) {
                std::map<std::string, int>::iterator existing = indexLookup.find( lineParts.at(i) );
                if ( existing == indexLookup.end() ) {
                    // This is a new index
                    // Split the current parts into their vParts
                    std::vector<std::string> vertexParts;
                    boost::split( vertexParts, lineParts.at(i), boost::is_any_of("/") );

                    Vec3* vertex = tempVertices[ atoi(vertexParts.at(0).c_str()) - 1 ];
                    vertices.push_back( vertex->x );
                    vertices.push_back( vertex->y );
                    vertices.push_back( vertex->z );

                    Vec3* normal = tempNormals[ atoi(vertexParts.at(2).c_str()) - 1 ];
                    vertices.push_back( normal->x );
                    vertices.push_back( normal->y );
                    vertices.push_back( normal->z );

                    vertices.push_back( currentMaterial->ambient.x );
                    vertices.push_back( currentMaterial->ambient.y );
                    vertices.push_back( currentMaterial->ambient.z );

                    vertices.push_back( currentMaterial->diffuse.x );
                    vertices.push_back( currentMaterial->diffuse.y );
                    vertices.push_back( currentMaterial->diffuse.z );

                    vertices.push_back( currentMaterial->specular.x );
                    vertices.push_back( currentMaterial->specular.y );
                    vertices.push_back( currentMaterial->specular.z );

                    vertices.push_back( currentMaterial->specularExponent );
                    vertices.push_back( currentMaterial->transparency );

                    indexLookup[ lineParts.at(i) ] = numVertices;
                    indexes.push_back( numVertices++ );
                } else {
                    // Get it from the lookup
                    indexes.push_back( existing->second );
                }
            }
        }
    }

    // Clean up all temp stuff
    std::for_each( tempVertices.begin(), tempVertices.end(), [] (Vec3* vec) {
        delete vec;
    });
    std::for_each( tempNormals.begin(), tempNormals.end(), [] (Vec3* vec) {
        delete vec;
    });
    std::for_each( _materials.begin(), _materials.end(), [] (std::pair<std::string,Material*> material) {
        delete material.second;
    });

    modelFile.close();
    return 0;
}

void MeshLoader::_parseMaterialLib( const char* filename ) {

    std::ifstream materialFile(filename);
    Material* currentMaterial;

    for( std::string line; std::getline( materialFile, line); ) {
        
        std::vector<std::string> lineParts;
        boost::split( lineParts, line, boost::is_any_of(" ") );

        if( lineParts.at(0) == "newmtl" ) {
           currentMaterial = new Material();
           strcpy( currentMaterial->name, lineParts.at(1).c_str() );
           _materials[lineParts.at(1)] = currentMaterial;
        }
        else if ( lineParts.at(0) == "Ka" ) {
            currentMaterial->ambient.set( atof(lineParts.at(1).c_str()), atof(lineParts.at(2).c_str()), atof(lineParts.at(3).c_str()) );
        }
        else if ( lineParts.at(0) == "Kd" ) {
            currentMaterial->diffuse.set( atof(lineParts.at(1).c_str()), atof(lineParts.at(2).c_str()), atof(lineParts.at(3).c_str()) );
        }
        else if ( lineParts.at(0) == "Ks" ) {
            currentMaterial->specular.set( atof(lineParts.at(1).c_str()), atof(lineParts.at(2).c_str()), atof(lineParts.at(3).c_str()) );
        }
        else if ( lineParts.at(0) == "d" ) {
            currentMaterial->transparency = 1.0 - atof(lineParts.at(1).c_str());
        }
        else if ( lineParts.at(0) == "Tr" ) {
            currentMaterial->transparency = atof(lineParts.at(1).c_str());
        }
        else if ( lineParts.at(0) == "Ns" ) {
            currentMaterial->specularExponent = atof(lineParts.at(1).c_str());
        }
    }

    materialFile.close();
}
