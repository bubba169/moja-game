#ifndef MOJAGAME_COMPONENT_TRANSFORM_H
#define MOJAGAME_COMPONENT_TRANSFORM_H

#include <Mojagame/Types.h>
#include <Mojagame/Component.h>
#include <Mojagame/math/Matrix.h>
#include <list>

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

        void globalToLocal( float* x, float* y );
        void localToGlobal( float* x, float* y );

        float getRotation();
        float getRotationDegrees();
        void setRotation( float val );
        void setRotationDegrees( float val );

        float getScaleX();
        float getScaleY();
        void setScaleX( float val );
        void setScaleY( float val );
        void setScale( float val );

        float getX();
        float getY();
        void setX( float val );
        void setY( float val );
        void setPosition( float x, float y );        

        TransformChildList::iterator begin();
        TransformChildList::iterator end();

    protected:

        // _parent and _childIndex are stored on the child but managed by the parent.
        Transform* _parent;
        int _childIndex;

        TransformChildList _children;
        void _reindexChildren();

        bool _childIndexesDirty;
        bool _worldMatrixDirty;
        bool _localMatrixDirty;

        Mat3 _worldTransform;
        Mat3 _globalTransform;

        float _x,_y,_scaleX,_scaleY,_rotation;
        
};

#endif