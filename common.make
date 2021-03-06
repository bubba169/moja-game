##
# CONFIG
##
CFLAGS=-std=c++11 -D _USE_MATH_DEFINES -D MG_LIBRARY
LIBS=
LIB_DIRS=
INCLUDE_DIRS=-Iinclude -Ilib/include
SRC = test/Main.cpp $(wildcard src/*.cpp) \
    $(wildcard src/math/*.cpp) \
    $(wildcard src/util/*.cpp) \
    $(wildcard src/component/*.cpp) \
    $(wildcard src/component/renderable/*.cpp) \
    $(wildcard src/renderer/*.cpp)
OUTPUT = output/objects/