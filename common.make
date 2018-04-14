##
# CONFIG
##
CFLAGS=-std=c++11 -D _USE_MATH_DEFINES
LIBS=
LIB_DIRS=
INCLUDE_DIRS=-Iinclude -Ilib/include
SRC = test/Main.cpp $(wildcard src/*.cpp) $(wildcard src/display/*.cpp) $(wildcard src/math/*.cpp) $(wildcard src/util/*.cpp) $(wildcard src/component/*.cpp) $(wildcard src/renderer/*.cpp)
OUTPUT = output/objects/