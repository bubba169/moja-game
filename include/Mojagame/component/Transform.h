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
        Transform* setRotation( float val );
        Transform* setRotationDegrees( float val );

        float getScaleX();
        float getScaleY();
        Transform* setScaleX( float val );
        Transform* setScaleY( float val );
        Transform* setScale( float val );

        float getX();
        float getY();
        Transform* setX( float val );
        Transform* setY( float val );
        Transform* setPosition( float x, float y );   
        
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
        void _regenerateChildren();

        float _x,_y,_scaleX,_scaleY,_rotation;

        Sprite* _sprite;
        
};

#endif