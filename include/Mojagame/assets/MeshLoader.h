#ifndef MOJAGAME_ASSETS_MESHLOADER_H
#define MOJAGAME_ASSETS_MESHLOADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <boost/algorithm/string.hpp>

#include <Mojagame/math/Vector.h>

struct Material {
    char name[100];
    Vec3 ambient;
    Vec3 diffuse;
    Vec3 specular;
    float specularExponent;
    float transparency;
};

class MeshLoader {

    public:
        MeshLoader();

        unsigned int load( const char* filename );
        std::vector<float> vertices;
        std::vector<unsigned short> indexes;
        int numVertices;

    private:
        void _parseMaterialLib( const char* filename );
        std::map<std::string, Material*> _materials;
};

#endif