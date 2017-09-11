#include <Mojagame/component/Transform.h>
#include <Mojagame/Component.h>
#include <Mojagame/Entity.h>
#include <Mojagame/Grapevine.h>

Transform::Transform() : 
    _childIndexesDirty(true),
    _worldMatrixDirty(true),
    _localMatrixDirty(true),
    _x(0),
    _y(0),
    _scaleX(1),
    _scaleY(1),
    _rotation(0)
{}

std::string Transform::getName() {
    return "Transform";
}

void Transform::globalToLocal( float* x, float* y ) {
    x = 
}

void Transform::addChild( Transform* child ) {
    if ( child->_parent != NULL ) {
        child->_parent->removeChild( child );
    }

    child->_parent = this;
    child->_childIndex = _children.size();
    _children.push_back( child );
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

TransformChildList::iterator Transform::begin() {
    return _children.begin();
}

TransformChildList::iterator Transform::end() {
    return _children.end();
}

