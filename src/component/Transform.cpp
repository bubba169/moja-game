#include <Mojagame/component/Transform.h>

std::string Transform::getName() {
    return "Transform";
}

void Transform::addChild( Transform* child ) {
    if ( child->_parent != NULL ) {
        child->_parent->removeChild( child );
    }

    child->_parent = this;
    _children.push_back( child );
}

void Transform::removeChild( Transform* child ) {
    child->_parent = NULL;
    _children.erase(std::remove(_children.begin(), _children.end(), child));
}

void Transform::setChildIndex( Transform* child, int index ) {
    if ( child->_parent == this ) {
        _children.erase(std::remove(_children.begin(), _children.end(), child));
        
        if (index >= _children.size()) {
            _children.insert( _children.end(), child );
        } else {
            _children.insert( _children.begin() + index, child );
        }
    }
}

Transform* Transform::getParent() {
    return _parent;
}


