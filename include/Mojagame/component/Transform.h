#ifndef MOJAGAME_COMPONENT_TRANSFORM_H
#define MOJAGAME_COMPONENT_TRANSFORM_H

class Transform;
class Component;
class std::list;

typedef std::list<Transform*>TransformChildList;

class Transform : public Component {

    public:
        Transform();
        virtual ~Transform() {};

        virtual std::string getName();

        Transform* getParent();
        void addChild( Transform* child );
        void removeChild( Transform* child );
        void setChildIndex( Transform* child, int index );
        int getChildIndex( Transform* child );

        TransformChildList::iterator begin();
        TransformChildList::iterator end();

    protected:

        // _parent and _childIndex are stored on the child but managed by the parent.
        Transform* _parent;
        int _childIndex;

        TransformChildList _children;
        void _reindexChildren();
        bool _childIndexesDirty;

};

#endif