##
# CONFIG
##
CFLAGS=-std=c++11
LIBS=
LIB_DIRS=
INCLUDE_DIRS=-Iinclude -Ilib/include
SRC = $(wildcard src/*.cpp) $(wildcard src/assets/*.cpp) $(wildcard src/math/*.cpp)
OUTPUT = output/objects/