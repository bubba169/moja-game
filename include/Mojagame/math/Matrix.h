#ifndef MOJAGAME_MATH_MATRIX_H
#define MOJAGAME_MATH_MATRIX_H

#include <cstring>
#include <cstdio>
#include <cmath>

class Mat4 {

    public:
        Mat4();
        Mat4( float* data );
        Mat4* identity();
        Mat4* prepend( Mat4* m );
        Mat4* append( Mat4* m );
        Mat4* copyFrom( Mat4* m );
        Mat4* copyFrom( float* m );
        Mat4* translate( float x, float y, float z );
        Mat4* rotateX( float theta );
        Mat4* rotateY( float theta );
        Mat4* rotateZ( float theta );
        Mat4* scaleX( float scale );
        Mat4* scaleY( float scale );
        Mat4* scaleZ( float scale );
        float determinant();
        Mat4* cofactor();
        Mat4* transpose();
        Mat4* multiply( float val );
        Mat4* inverse();

        void print();

        float get( int row, int col );
        void set( int row, int col, float val );
        float* getData();

    protected:
        float _data[16];
};

#endif