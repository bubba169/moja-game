#include <Mojagame.h>

Transform::Transform( Sprite* sprite ) : 
    _childIndexesDirty(true),
    _globalMatrixDirty(true),
    _localMatrixDirty(true),
    _x(0),
    _y(0),
    _scaleX(1),
    _scaleY(1),
    _rotation(0),
    _sprite(sprite),
    _parent(NULL)
{}

void Transform::globalToLocal( float* x, float* y ) {
    getInverseGlobalMatrix()->transform(x, y);
}

void Transform::localToGlobal( float* x, float* y ) {
    getGlobalMatrix()->transform(x, y);
}

Mat3* Transform::getGlobalMatrix() {
    if (_globalMatrixDirty) _regenerateGlobalMatrix();
    return &_globalTransform;
}

Mat3* Transform::getInverseGlobalMatrix() {
    if (_globalMatrixDirty) _regenerateGlobalMatrix();
    return &_inverseGlobalTransform;
}

Mat3* Transform::getLocalMatrix() {
    if (_localMatrixDirty) _regenerateLocalMatrix();
    return &_localTransform;
}

void Transform::_regenerateLocalMatrix() {
    _localTransform.identity();
    _localTransform.scaleX( _scaleX );
    _localTransform.scaleY( _scaleY );
    _localTransform.rotate( _rotation );
    _localTransform.translate( _x, _y );
    _localMatrixDirty = false;
}

void Transform::_regenerateGlobalMatrix() {
    if (_localMatrixDirty) {
        _regenerateLocalMatrix();
    }
   
    if (_parent != NULL) {
        _globalTransform.copyFrom( _parent->getGlobalMatrix() );
        _globalTransform.append( &_localTransform );
    } else {
        _globalTransform.copyFrom( &_localTransform );
    }

    _inverseGlobalTransform.copyFrom( &_globalTransform );
    _inverseGlobalTransform.inverse();

    _globalMatrixDirty = false;

    _regenerateChildren();
}

void Transform::addChild( Transform* child ) {
    if ( child->_parent != NULL ) {
        child->_parent->removeChild( child );
    }

    child->_parent = this;
    child->_childIndex = _children.size();
    _children.push_back( child );

    _regenerateChildren();
}

void Transform::removeChild( Transform* child ) {
    child->_parent = NULL;
    _children.erase(std::remove(_children.begin(), _children.end(), child));
    
    _childIndexesDirty = true;
}

void Transform::setChildIndex( Transform* child, int index ) {
    if ( child->_parent == this ) {
        _children.erase(std::remove(_children.begin(), _children.end(), child));
        
        if (index >= _children.size()) {
            _children.insert( _children.end(), child );
        } else {
            TransformChildList::iterator it = _children.begin();
            if (index > 0) std::advance( it, index );
            _children.insert( it, child );
        }

        _childIndexesDirty = true;
    }   
}

int Transform::getChildIndex( Transform* child ) {
    if ( _childIndexesDirty ) {
        _reindexChildren();
    }
    return child->_childIndex;
}

Transform* Transform::getParent() {
    return _parent;
}

void Transform::_reindexChildren() {
    int i(0);
    std::for_each( _children.begin(), _children.end(), [i]( Transform* child ) mutable {
        child->_childIndex = i++;
    });
}

void Transform::_regenerateChildren() {
    std::for_each( _children.begin(), _children.end(), []( Transform* child ) mutable {
        child->_regenerateGlobalMatrix();
    });
}

TransformChildList::iterator Transform::begin() {
    return _children.begin();
}

TransformChildList::iterator Transform::end() {
    return _children.end();
}

Sprite* Transform::getSprite() {
    return _sprite;
}

/**
 * Getters and setters
 */


float Transform::getRotation() {
    return -_rotation;
}

float Transform::getRotationDegrees() {
    return getRotation() * (180.0/M_PI);
}

Transform* Transform::setRotation( float val ) {
    _rotation = -val;
    _localMatrixDirty = true;
    _globalMatrixDirty = true;
    return this;
}

Transform* Transform::setRotationDegrees( float val ) {
    setRotation(val * (M_PI/180.0));
    return this;
}

float Transform::getScaleX() {
    return _scaleX;
}

float Transform::getScaleY() {
    return _scaleY;
}

Transform* Transform::setScaleX( float val ) {
    _scaleX = val;
    _localMatrixDirty = true;
    _globalMatrixDirty = true;
    return this;
}

Transform* Transform::setScaleY( float val ) {
    _scaleY = val;
    _localMatrixDirty = true;
    _globalMatrixDirty = true;
    return this;
}

Transform* Transform::setScale( float val ) {
    _scaleX = val;
    _scaleY = val;
    _localMatrixDirty = true;
    _globalMatrixDirty = true;
    return this;
}

float Transform::getX() {
    return _x;
}

float Transform::getY() {
    return _y;
}

Transform* Transform::setX( float val ) {
    _x = val;
    _localMatrixDirty = true;
    _globalMatrixDirty = true;
    return this;
}

Transform* Transform::setY( float val ) {
    _y = val;
    _localMatrixDirty = true;
    _globalMatrixDirty = true;
    return this;
}

Transform* Transform::setPosition( float x, float y ) {
    _y = y;
    _x = x;
    _localMatrixDirty = true;
    _globalMatrixDirty = true;
    return this;
}

