#ifndef MOJAGAME_VECTOR_MATH_H
#define MOJAGAME_VECTOR_MATH_H

class Vec3 {
    public:
        float x, y, z;

        Vec3();
        Vec3( float x, float y, float z );
        void set( float x, float y, float z );
};

#endif