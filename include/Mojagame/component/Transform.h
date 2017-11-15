#ifndef MOJAGAME_COMPONENT_TRANSFORM_H
#define MOJAGAME_COMPONENT_TRANSFORM_H

#include <Mojagame/Types.h>
#include <Mojagame/math/Matrix.h>
#include <list>

class Transform {

    public:
        Transform( Sprite* object );
        virtual ~Transform() {};

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
        
        Mat3* getGlobalMatrix();
        Mat3* getInverseGlobalMatrix();
        Mat3* getLocalMatrix();

        TransformChildList::iterator begin();
        TransformChildList::iterator end();

        Sprite* getSprite();

    protected:

        // _parent and _childIndex are stored on the child but managed by the parent.
        Transform* _parent;
        int _childIndex;

        TransformChildList _children;
        void _reindexChildren();

        bool _childIndexesDirty;
        bool _globalMatrixDirty;
        bool _localMatrixDirty;

        Mat3 _globalTransform;
        Mat3 _inverseGlobalTransform;
        Mat3 _localTransform;

        void _regenerateLocalMatrix();
        void _regenerateGlobalMatrix();

        float _x,_y,_scaleX,_scaleY,_rotation;

        Sprite* _sprite;
        
};

#endif