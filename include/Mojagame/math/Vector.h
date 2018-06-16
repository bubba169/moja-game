#pragma once

class Vec2 {
    public:
        Vec2();
        Vec2( float x, float y );
        void set( float x, float y );
};

class Vec3 {
    public:
        float x, y, z;

        Vec3();
        Vec3( float x, float y, float z );
        void set( float x, float y, float z );
};