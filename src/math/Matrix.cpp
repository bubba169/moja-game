#include <Mojagame/math/Matrix.h>

/**
 * Mat4
 */

Mat4::Mat4() {
    identity();
}

Mat4::Mat4( float* data ) {
    copyFrom(data);
}

Mat4* Mat4::copyFrom( Mat4* m ) {
    std::memcpy( _data, m->_data, 16 * 4 );
    return this;
}

Mat4* Mat4::copyFrom( float* m ) {
    std::memcpy( _data, m, 16 * 4 );
    return this;
}

float Mat4::get( int row, int col ) {
    return _data[ ((row - 1) * 4) + (col - 1) ];
}

void Mat4::set( int row, int col, float val ) {
    _data[ ((row - 1) * 4) + (col - 1) ] = val;
}

float* Mat4::getData() {
    return _data;
}

Mat4* Mat4::identity() {
    _data[0] = 1;  _data[1] = 0;  _data[2] = 0;  _data[3] = 0;
    _data[4] = 0;  _data[5] = 1;  _data[6] = 0;  _data[7] = 0;
    _data[8] = 0;  _data[9] = 0;  _data[10] = 1; _data[11] = 0;
    _data[12] = 0; _data[13] = 0; _data[14] = 0; _data[15] = 1;

    return this;
}

Mat4* Mat4::prepend( Mat4* m ) {
    float elements[] = {
        (m->get(1,1) * get(1,1)) + (m->get(1,2) * get(2,1)) + (m->get(1,3) * get(3,1)) + (m->get(1,4) * get(4,1)),
        (m->get(1,1) * get(1,2)) + (m->get(1,2) * get(2,2)) + (m->get(1,3) * get(3,2)) + (m->get(1,4) * get(4,2)),
        (m->get(1,1) * get(1,3)) + (m->get(1,2) * get(2,3)) + (m->get(1,3) * get(3,3)) + (m->get(1,4) * get(4,3)),
        (m->get(1,1) * get(1,4)) + (m->get(1,2) * get(2,4)) + (m->get(1,3) * get(3,4)) + (m->get(1,4) * get(4,4)),
        (m->get(2,1) * get(1,1)) + (m->get(2,2) * get(2,1)) + (m->get(2,3) * get(3,1)) + (m->get(2,4) * get(4,1)),
        (m->get(2,1) * get(1,2)) + (m->get(2,2) * get(2,2)) + (m->get(2,3) * get(3,2)) + (m->get(2,4) * get(4,2)),
        (m->get(2,1) * get(1,3)) + (m->get(2,2) * get(2,3)) + (m->get(2,3) * get(3,3)) + (m->get(2,4) * get(4,3)),
        (m->get(2,1) * get(1,4)) + (m->get(2,2) * get(2,4)) + (m->get(2,3) * get(3,4)) + (m->get(2,4) * get(4,4)),
        (m->get(3,1) * get(1,1)) + (m->get(3,2) * get(2,1)) + (m->get(3,3) * get(3,1)) + (m->get(3,4) * get(4,1)),
        (m->get(3,1) * get(1,2)) + (m->get(3,2) * get(2,2)) + (m->get(3,3) * get(3,2)) + (m->get(3,4) * get(4,2)),
        (m->get(3,1) * get(1,3)) + (m->get(3,2) * get(2,3)) + (m->get(3,3) * get(3,3)) + (m->get(3,4) * get(4,3)),
        (m->get(3,1) * get(1,4)) + (m->get(3,2) * get(2,4)) + (m->get(3,3) * get(3,4)) + (m->get(3,4) * get(4,4)),
        (m->get(4,1) * get(1,1)) + (m->get(4,2) * get(2,1)) + (m->get(4,3) * get(3,1)) + (m->get(4,4) * get(4,1)),
        (m->get(4,1) * get(1,2)) + (m->get(4,2) * get(2,2)) + (m->get(4,3) * get(3,2)) + (m->get(4,4) * get(4,2)),
        (m->get(4,1) * get(1,3)) + (m->get(4,2) * get(2,3)) + (m->get(4,3) * get(3,3)) + (m->get(4,4) * get(4,3)),
        (m->get(4,1) * get(1,4)) + (m->get(4,2) * get(2,4)) + (m->get(4,3) * get(3,4)) + (m->get(4,4) * get(4,4))
    };
    return copyFrom(elements);
}

Mat4* Mat4::append( Mat4* m ) {
    float elements[] = {
        (get(1,1) * m->get(1,1)) + (get(1,2) * m->get(2,1)) + (get(1,3) * m->get(3,1)) + (get(1,4) * m->get(4,1)),
        (get(1,1) * m->get(1,2)) + (get(1,2) * m->get(2,2)) + (get(1,3) * m->get(3,2)) + (get(1,4) * m->get(4,2)),
        (get(1,1) * m->get(1,3)) + (get(1,2) * m->get(2,3)) + (get(1,3) * m->get(3,3)) + (get(1,4) * m->get(4,3)),
        (get(1,1) * m->get(1,4)) + (get(1,2) * m->get(2,4)) + (get(1,3) * m->get(3,4)) + (get(1,4) * m->get(4,4)),
        (get(2,1) * m->get(1,1)) + (get(2,2) * m->get(2,1)) + (get(2,3) * m->get(3,1)) + (get(2,4) * m->get(4,1)),
        (get(2,1) * m->get(1,2)) + (get(2,2) * m->get(2,2)) + (get(2,3) * m->get(3,2)) + (get(2,4) * m->get(4,2)),
        (get(2,1) * m->get(1,3)) + (get(2,2) * m->get(2,3)) + (get(2,3) * m->get(3,3)) + (get(2,4) * m->get(4,3)),
        (get(2,1) * m->get(1,4)) + (get(2,2) * m->get(2,4)) + (get(2,3) * m->get(3,4)) + (get(2,4) * m->get(4,4)),
        (get(3,1) * m->get(1,1)) + (get(3,2) * m->get(2,1)) + (get(3,3) * m->get(3,1)) + (get(3,4) * m->get(4,1)),
        (get(3,1) * m->get(1,2)) + (get(3,2) * m->get(2,2)) + (get(3,3) * m->get(3,2)) + (get(3,4) * m->get(4,2)),
        (get(3,1) * m->get(1,3)) + (get(3,2) * m->get(2,3)) + (get(3,3) * m->get(3,3)) + (get(3,4) * m->get(4,3)),
        (get(3,1) * m->get(1,4)) + (get(3,2) * m->get(2,4)) + (get(3,3) * m->get(3,4)) + (get(3,4) * m->get(4,4)),
        (get(4,1) * m->get(1,1)) + (get(4,2) * m->get(2,1)) + (get(4,3) * m->get(3,1)) + (get(4,4) * m->get(4,1)),
        (get(4,1) * m->get(1,2)) + (get(4,2) * m->get(2,2)) + (get(4,3) * m->get(3,2)) + (get(4,4) * m->get(4,2)),
        (get(4,1) * m->get(1,3)) + (get(4,2) * m->get(2,3)) + (get(4,3) * m->get(3,3)) + (get(4,4) * m->get(4,3)),
        (get(4,1) * m->get(1,4)) + (get(4,2) * m->get(2,4)) + (get(4,3) * m->get(3,4)) + (get(4,4) * m->get(4,4))
    };
    return copyFrom(elements);
}

Mat4* Mat4::translate( float x, float y, float z ) {
    set(1,4, get(1,4) + x);
    set(2,4, get(2,4) + y);
    set(3,4, get(3,4) + z);
    return this;
}

Mat4* Mat4::rotateX( float theta ) {
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);
    float elements[] = {
        1, 0, 0, 0,
        0, cosTheta, sinTheta, 0,
        0, sinTheta, cosTheta, 0,
        0, 0, 0, 1
    };
    Mat4 adjustment(elements);
    return prepend(&adjustment);
}

Mat4* Mat4::rotateY( float theta ) {
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);
    float elements[] = {
        cosTheta, 0, sinTheta, 0,
        0, 1, 0, 0,
        -sinTheta, 0, cosTheta, 0,
        0, 0, 0, 1
    };
    Mat4 adjustment(elements);
    return prepend(&adjustment);
}

Mat4* Mat4::rotateZ( float theta ) {
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);
    float elements[] = {
        cosTheta, sinTheta, 0, 0,
        sinTheta, cosTheta, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    Mat4 adjustment(elements);
    return prepend(&adjustment);
}

Mat4* Mat4::scaleX( float scale ) {
    Mat4 adjustment;
    adjustment.set(1,1,scale);
    return prepend( &adjustment );
}

Mat4* Mat4::scaleY( float scale ) {
    Mat4 adjustment;
    adjustment.set(2,2,scale);
    return prepend( &adjustment );
}

Mat4* Mat4::scaleZ( float scale ) {
    Mat4 adjustment;
    adjustment.set(3,3,scale);
    return prepend( &adjustment );
}

float Mat4::determinant() {
    return (get(1,1) * ( (get(2,2)*((get(3,3)*get(4,4))-(get(3,4)*get(4,3)))) - (get(2,3)*((get(3,2)*get(4,4))-(get(3,4)*get(4,2)))) + (get(2,4)*((get(3,2)*get(4,3))-(get(3,3)*get(4,2)))) ))
         - (get(1,2) * ( (get(2,1)*((get(3,3)*get(4,4))-(get(3,4)*get(4,3)))) - (get(2,3)*((get(3,1)*get(4,4))-(get(3,4)*get(4,1)))) + (get(2,4)*((get(3,1)*get(4,3))-(get(3,3)*get(4,1)))) ))
         + (get(1,3) * ( (get(2,1)*((get(3,2)*get(4,4))-(get(3,4)*get(4,2)))) - (get(2,2)*((get(3,1)*get(4,4))-(get(3,4)*get(4,1)))) + (get(2,4)*((get(3,1)*get(4,2))-(get(3,2)*get(4,1)))) ))
         - (get(1,4) * ( (get(2,1)*((get(3,2)*get(4,3))-(get(3,3)*get(4,2)))) - (get(2,2)*((get(3,1)*get(4,3))-(get(3,3)*get(4,1)))) + (get(2,3)*((get(3,1)*get(4,2))-(get(3,2)*get(4,1)))) ));
}

Mat4* Mat4::cofactor() {
    float elements[] = {
         ( (get(2,2)*((get(3,3)*get(4,4))-(get(3,4)*get(4,3)))) - (get(2,3)*((get(3,2)*get(4,4))-(get(3,4)*get(4,2)))) + (get(2,4)*((get(3,2)*get(4,3))-(get(3,3)*get(4,2)))) ),
        -( (get(2,1)*((get(3,3)*get(4,4))-(get(3,4)*get(4,3)))) - (get(2,3)*((get(3,1)*get(4,4))-(get(3,4)*get(4,1)))) + (get(2,4)*((get(3,1)*get(4,3))-(get(3,3)*get(4,1)))) ),
         ( (get(2,1)*((get(3,2)*get(4,4))-(get(3,4)*get(4,2)))) - (get(2,2)*((get(3,1)*get(4,4))-(get(3,4)*get(4,1)))) + (get(2,4)*((get(3,1)*get(4,2))-(get(3,2)*get(4,1)))) ),
        -( (get(2,1)*((get(3,2)*get(4,3))-(get(3,3)*get(4,2)))) - (get(2,2)*((get(3,1)*get(4,3))-(get(3,3)*get(4,1)))) + (get(2,3)*((get(3,1)*get(4,2))-(get(3,2)*get(4,1)))) ),
        -( (get(1,2)*((get(3,3)*get(4,4))-(get(3,4)*get(4,3)))) - (get(1,3)*((get(3,2)*get(4,4))-(get(3,4)*get(4,2)))) + (get(1,4)*((get(3,2)*get(4,3))-(get(3,3)*get(4,2)))) ),
         ( (get(1,1)*((get(3,3)*get(4,4))-(get(3,4)*get(4,3)))) - (get(1,3)*((get(3,1)*get(4,4))-(get(3,4)*get(4,1)))) + (get(1,4)*((get(3,1)*get(4,3))-(get(3,3)*get(4,1)))) ),
        -( (get(1,1)*((get(3,2)*get(4,4))-(get(3,4)*get(4,2)))) - (get(1,2)*((get(3,1)*get(4,4))-(get(3,4)*get(4,1)))) + (get(1,4)*((get(3,1)*get(4,2))-(get(3,2)*get(4,1)))) ),
         ( (get(1,1)*((get(3,2)*get(4,3))-(get(3,3)*get(4,2)))) - (get(1,2)*((get(3,1)*get(4,3))-(get(3,3)*get(4,1)))) + (get(1,3)*((get(3,1)*get(4,2))-(get(3,2)*get(4,1)))) ),
         ( (get(1,2)*((get(2,3)*get(4,4))-(get(2,4)*get(4,3)))) - (get(1,3)*((get(2,2)*get(4,4))-(get(2,4)*get(4,2)))) + (get(1,4)*((get(2,2)*get(4,3))-(get(2,3)*get(4,2)))) ),
        -( (get(1,1)*((get(2,3)*get(4,4))-(get(2,4)*get(4,3)))) - (get(1,3)*((get(2,1)*get(4,4))-(get(2,4)*get(4,1)))) + (get(1,4)*((get(2,1)*get(4,3))-(get(2,3)*get(4,1)))) ),
         ( (get(1,1)*((get(2,2)*get(4,4))-(get(2,4)*get(4,2)))) - (get(1,2)*((get(2,1)*get(4,4))-(get(2,4)*get(4,1)))) + (get(1,4)*((get(2,1)*get(4,2))-(get(2,2)*get(4,1)))) ),
        -( (get(1,1)*((get(2,2)*get(4,3))-(get(2,3)*get(4,2)))) - (get(1,2)*((get(2,1)*get(4,3))-(get(2,3)*get(4,1)))) + (get(1,3)*((get(2,1)*get(4,2))-(get(2,2)*get(4,1)))) ),
        -( (get(1,2)*((get(2,3)*get(3,4))-(get(2,4)*get(3,3)))) - (get(1,3)*((get(2,2)*get(3,4))-(get(2,4)*get(3,2)))) + (get(1,4)*((get(2,2)*get(3,3))-(get(2,3)*get(3,2)))) ),
         ( (get(1,1)*((get(2,3)*get(3,4))-(get(2,4)*get(3,3)))) - (get(1,3)*((get(2,1)*get(3,4))-(get(2,4)*get(3,1)))) + (get(1,4)*((get(2,1)*get(3,3))-(get(2,3)*get(3,1)))) ),
        -( (get(1,1)*((get(2,2)*get(3,4))-(get(2,4)*get(3,2)))) - (get(1,2)*((get(2,1)*get(3,4))-(get(2,4)*get(3,1)))) + (get(1,4)*((get(2,1)*get(3,2))-(get(2,2)*get(3,1)))) ),
         ( (get(1,1)*((get(2,2)*get(3,3))-(get(2,3)*get(3,2)))) - (get(1,2)*((get(2,1)*get(3,3))-(get(2,3)*get(3,1)))) + (get(1,3)*((get(2,1)*get(3,2))-(get(2,2)*get(3,1)))) )
    };
    return copyFrom( elements );
}

Mat4* Mat4::transpose() {
    float elements[] = {
        get(1,1), get(2,1), get(3,1), get(4,1),
        get(1,2), get(2,2), get(3,2), get(4,2),
        get(1,3), get(2,3), get(3,3), get(4,3),
        get(1,4), get(2,4), get(3,4), get(4,4)
    };
    return copyFrom(elements);
}

Mat4* Mat4::multiply( float val ) {
    for( int i(0); i < 16; ++i) {
        _data[i] *= val;
    }
    return this;
}

Mat4* Mat4::inverse( ) {
    float d = determinant();
    if (d) {
        return cofactor()
        ->multiply(d)
        ->transpose();
    }
    return this;
}

void Mat4::print() {
    printf( "[%f,%f,%f,%f]\n", get(1,1), get(1,2), get(1,3), get(1,4));
    printf( "[%f,%f,%f,%f]\n", get(2,1), get(2,2), get(2,3), get(2,4));
    printf( "[%f,%f,%f,%f]\n", get(3,1), get(3,2), get(3,3), get(3,4));
    printf( "[%f,%f,%f,%f]\n\n", get(4,1), get(4,2), get(4,3), get(4,4));
}

/**
 * Mat3
 */

Mat3::Mat3() {
    identity();
}

Mat3::Mat3( float* data ) {
    copyFrom(data);
}

Mat3* Mat3::copyFrom( Mat3* m ) {
    return copyFrom(m->data);
}

Mat3* Mat3::copyFrom( float* m ) {
    std::memcpy( _data, m, 9 * 4 );
    return this;
}

float Mat3::get( int row, int col ) {
    return _data[ ((row - 1) * 3) + (col - 1) ];
}

void Mat3::set( int row, int col, float val ) {
    _data[ ((row - 1) * 3) + (col - 1) ] = val;
}

float* Mat3::getData() {
    return _data;
}

Mat3* Mat3::identity() {
    _data[0] = 1;  _data[1] = 0;  _data[2] = 0;  
    _data[3] = 0;  _data[4] = 1;  _data[5] = 0; 
    _data[6] = 0;  _data[7] = 0;  _data[8] = 1;

    return this;
}

Mat3* Mat3::prepend( Mat3* m ) {
    float elements[] = {
        (m->get(1,1) * get(1,1)) + (m->get(1,2) * get(2,1)) + (m->get(1,3) * get(3,1)),
        (m->get(1,1) * get(1,2)) + (m->get(1,2) * get(2,2)) + (m->get(1,3) * get(3,2)),
        (m->get(1,1) * get(1,3)) + (m->get(1,2) * get(2,3)) + (m->get(1,3) * get(3,3)),
        (m->get(2,1) * get(1,1)) + (m->get(2,2) * get(2,1)) + (m->get(2,3) * get(3,1)),
        (m->get(2,1) * get(1,2)) + (m->get(2,2) * get(2,2)) + (m->get(2,3) * get(3,2)),
        (m->get(2,1) * get(1,3)) + (m->get(2,2) * get(2,3)) + (m->get(2,3) * get(3,3)),
        (m->get(3,1) * get(1,1)) + (m->get(3,2) * get(2,1)) + (m->get(3,3) * get(3,1)),
        (m->get(3,1) * get(1,2)) + (m->get(3,2) * get(2,2)) + (m->get(3,3) * get(3,2)),
        (m->get(3,1) * get(1,3)) + (m->get(3,2) * get(2,3)) + (m->get(3,3) * get(3,3))
    };
    return copyFrom(elements);
}

Mat3* Mat3::append( Mat3* m ) {
    float elements[] = {
        (get(1,1) * m->get(1,1)) + (get(1,2) * m->get(2,1)) + (get(1,3) * m->get(3,1)),
        (get(1,1) * m->get(1,2)) + (get(1,2) * m->get(2,2)) + (get(1,3) * m->get(3,2)),
        (get(1,1) * m->get(1,3)) + (get(1,2) * m->get(2,3)) + (get(1,3) * m->get(3,3)),
        (get(2,1) * m->get(1,1)) + (get(2,2) * m->get(2,1)) + (get(2,3) * m->get(3,1)),
        (get(2,1) * m->get(1,2)) + (get(2,2) * m->get(2,2)) + (get(2,3) * m->get(3,2)),
        (get(2,1) * m->get(1,3)) + (get(2,2) * m->get(2,3)) + (get(2,3) * m->get(3,3)),
        (get(3,1) * m->get(1,1)) + (get(3,2) * m->get(2,1)) + (get(3,3) * m->get(3,1)),
        (get(3,1) * m->get(1,2)) + (get(3,2) * m->get(2,2)) + (get(3,3) * m->get(3,2)),
        (get(3,1) * m->get(1,3)) + (get(3,2) * m->get(2,3)) + (get(3,3) * m->get(3,3))
    };
    return copyFrom(elements);
}

Mat3* Mat3::translate( float x, float y ) {
    set(1,3, get(1,3) + x);
    set(2,3, get(2,3) + y);
    return this;
}

Mat3* Mat3::rotate( float theta ) {
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);
    float elements[] = {
        cosTheta, sinTheta, 0,
        -sinTheta, cosTheta, 0,
        0, 0, 1
    };
    Mat3 adjustment(elements);
    return prepend(&adjustment);
}

Mat3* Mat3::scaleX( float scale ) {
    Mat3 adjustment;
    adjustment.set(1,1,scale);
    return prepend( &adjustment );
}

Mat3* Mat3::scaleY( float scale ) {
    Mat3 adjustment;
    adjustment.set(2,2,scale);
    return prepend( &adjustment );
}

float Mat3::determinant() {
    return (get(1,1) * ((get(2,2) * get(3,3)) - (get(2,3) * get(3,2))))
         - (get(1,2) * ((get(2,1) * get(3,3)) - (get(2,3) * get(3,1))))
         + (get(1,3) * ((get(2,1) * get(3,2)) - (get(2,2) * get(3,1))));
}

Mat3* Mat3::cofactor() {
    float elements[] = {
         (get(2,2) * get(3,3)) - (get(2,3) * get(3,2)),
        -(get(2,1) * get(3,3)) - (get(2,3) * get(3,1)),
         (get(2,1) * get(3,2)) - (get(2,2) * get(3,1)),

        -(get(1,2) * get(3,3)) - (get(1,3) * get(3,2)),
         (get(1,1) * get(3,3)) - (get(1,3) * get(3,1)),
        -(get(1,1) * get(3,2)) - (get(1,2) * get(3,1)),

         (get(1,2) * get(2,3)) - (get(1,3) * get(2,2)),
        -(get(1,1) * get(2,3)) - (get(1,3) * get(2,1)),
         (get(1,1) * get(2,2)) - (get(1,2) * get(2,1))
              
    };
    return copyFrom( elements );
}

Mat3* Mat3::transpose() {
    float elements[] = {
        get(1,1), get(2,1), get(3,1),
        get(1,2), get(2,2), get(3,2),
        get(1,3), get(2,3), get(3,3)
    };
    return copyFrom(elements);
}

Mat3* Mat3::multiply( float val ) {
    for( int i(0); i < 9; ++i) {
        _data[i] *= val;
    }
    return this;
}

Mat3* Mat3::inverse( ) {
    float d = determinant();
    if (d) {
        return cofactor()
        ->multiply(d)
        ->transpose();
    }
    return this;
}

void Mat3::print() {
    printf( "[%f,%f,%f]\n", get(1,1), get(1,2), get(1,3));
    printf( "[%f,%f,%f]\n", get(2,1), get(2,2), get(2,3));
    printf( "[%f,%f,%f]\n", get(3,1), get(3,2), get(3,3));
}