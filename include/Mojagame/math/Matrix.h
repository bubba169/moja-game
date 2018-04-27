#ifndef MOJAGAME_MATH_MATRIX_H
#define MOJAGAME_MATH_MATRIX_H

#include <cstring>
#include <cstdio>
#include <cmath>

class Mat3;
class Mat4;

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
        Mat4* fromMat3( Mat3* m );

        void print();

        float get( int row, int col );
        void set( int row, int col, float val );
        float* getData();

    protected:
        float _data[16];
};

class Mat3 {
    
    public:
        Mat3();
        Mat3( float* data );
        Mat3* identity();
        Mat3* prepend( Mat3* m );
        Mat3* append( Mat3* m );
        Mat3* copyFrom( Mat3* m );
        Mat3* copyFrom( float* m );
        Mat3* translate( float x, float y );
        Mat3* rotate( float theta );
        Mat3* scaleX( float scale );
        Mat3* scaleY( float scale );
        float determinant();
        Mat3* cofactor();
        Mat3* transpose();
        Mat3* multiply( float val );
        Mat3* inverse();

        void transform( float* x, float* y );

        void print();

        float get( int row, int col );
        void set( int row, int col, float val );
        float* getData();
    
    protected:
        float _data[9];
    };

#endif