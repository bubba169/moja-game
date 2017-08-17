#ifndef MOJAGAME_UTIL_COLOUR_H
#define MOJAGAME_UTIL_COLOUR_H

class Colour {
    public:

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

#endif