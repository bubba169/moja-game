#pragma once

const unsigned int COLOUR_WHITE = 0xFFFFFFFF;
const unsigned int COLOUR_BLACK = 0xFF000000;
const unsigned int COLOUR_BLUE = 0xFF0000FF;
const unsigned int COLOUR_GREEN = 0xFF00FF00;
const unsigned int COLOUR_RED = 0xFFFF0000;

class Colour {
    public:
        Colour();
        Colour(unsigned int val);
        Colour( int r, int g, int b);
        Colour( int r, int g, int b, float a);

        void set( unsigned int val );
        void set( int r, int g, int b );
        void set( int r, int g, int b, float a );

        operator int() { return get(); };

        unsigned int get();
        int getRed();
        int getBlue();
        int getGreen();
        float getAlpha();

        void setRed( int r );
        void setGreen( int g );
        void setBlue( int b );
        void setAlpha( float a );

        int getGrey();

    protected:
        unsigned int _value;
};