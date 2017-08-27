##
# CONFIG
##
CFLAGS=-std=c++11
LIBS=
LIB_DIRS=
INCLUDE_DIRS=-Iinclude -Ilib/include
SRC = $(wildcard src/*.cpp) $(wildcard src/math/*.cpp) $(wildcard src/component/*.cpp) $(wildcard src/component/renderer/*.cpp) $(wildcard src/util/*.cpp)
OUTPUT = output/objects/