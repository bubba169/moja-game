#ifndef MOJAGAME_COMPONENT_H
#define MOJAGAME_COMPONENT_H

#include <string>

class Component {

    public:
        std::string getType();
        std::string getName();
        int getEntityId();

    protected:
        std::string _type;
        std::string _name;
        int entityId;

};

#endif