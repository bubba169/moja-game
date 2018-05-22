#include <Mojagame.h>

Colour::Colour() {
    set(0);
}

Colour::Colour( unsigned int val ) {
    set(val);
}

Colour::Colour( int r, int g, int b ) {
    set(r, g, b, 1);
}

Colour::Colour( int r, int g, int b, float a ) {
    set(r, g, b, a);
}

void Colour::set( unsigned int val ) {
    _value = val;
}

void Colour::set( int r, int g, int b ) {
    setRed(r);
    setGreen(g);
    setBlue(b);
}

void Colour::set( int r, int g, int b, float a ) {
    setRed(r);
    setGreen(g);
    setBlue(b);
    setAlpha(a);
}

void Colour::setBlue( int val ) {
    val = std::min( 255, std::max( val, 0 ));
    _value = (0xFFFFFF00 & _value) + val;
}

void Colour::setGreen( int val ) {
    val = std::min( 255, std::max( val, 0 ));
    _value = (0xFFFF00FF & _value) + (val << 8);
}

void Colour::setRed( int val ) {
    val = std::min( 255, std::max( val, 0 ));
    _value = (0xFF00FFFF & _value) + (val << 16);
}

void Colour::setAlpha( float val ) {
    val = std::min( 1.0f, std::max( val, 0.0f ));
    int intVal = (int)round(intVal * 255);
    _value = (0x00FFFFFF & _value) + (intVal << 24);
}

int Colour::getBlue() {
    return _value & 0x000000FF;
}

int Colour::getGreen() {
    return (_value & 0x0000FF00) >> 8;
}

int Colour::getRed() {
    return (_value & 0x00FF0000) >> 16;
}

float Colour::getAlpha() {
    return ((_value & 0xFF000000) >> 24) / 255.0f;
}

unsigned int Colour::get() {
    return _value;
}

