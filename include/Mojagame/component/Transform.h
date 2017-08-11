#ifndef MOJAGAME_COMPONENT_TRANSFORM_H
#define MOJAGAME_COMPONENT_TRANSFORM_H

#include <Mojagame/Component.h>

class Transform : public Component {

    public:
        virtual std::string getName();

        Transform* getParent();
        void addChild( Transform* child );
        void removeChild( Transform* child );
        void setChildIndex( Transform* child, int index );

    protected:
        Transform* _parent;
        std::vector<Transform*> _children;

};

#endif