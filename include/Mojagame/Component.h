#ifndef MOJAGAME_COMPONENT_H
#define MOJAGAME_COMPONENT_H

#include <string>

enum ComponentType {

}

class Component {

    public:
        std::string getName();
        int getType();

    protected:
        std::string _name;

};

#endif