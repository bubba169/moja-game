# Use the GCC compiler
CC=g++

#Compiler flags
CFLAGS=-std=c++11

LIBS=-lglfw3
INCLUDE_DIRS=-Iinclude -Ilib/include
PCH_INCLUDE=-include include/Mojagame/PreCompiledHeaders.hpp
SRC_FILES = src/*.cpp src/assets/*.cpp src/math/*.cpp

# All about that linux
LINUX_LIBS=-lGL -lX11 -lXxf86vm -lpthread -lXrandr -ldl -lXinerama -lXcursor
LINUX_LIB_DIRS=-Llib/linux64
LINUX_DEFINES=-D DESKTOP -D LINUX -D GLFW_INCLUDE_ES2
LINUX_SRC= src/native/platform/GLFWPlatform.cpp
linux:
	$(CC) -g $(PCH_INCLUDE) ${LINUX_DEFINES} ${CFLAGS} $(SRC_FILES) ${LINUX_SRC} $(LINUX_LIB_DIRS) $(INCLUDE_DIRS) $(LIBS) $(LINUX_LIBS) -o output/hello

linux_headers:
	$(CC) -g ${LINUX_DEFINES} ${CFLAGS} include/Mojagame/PreCompiledHeaders.hpp $(INCLUDE_DIRS)

# Stuff for mac
MAC_LIBS=-framework OpenGL -framework Cocoa -framework CoreVideo -framework IOKit
MAC_LIB_DIRS=-Llib/mac64
MAC_DEFINES=-D DESKTOP -D MACOS -D GLFW_INCLUDE_ES2
MAC_SRC= src/native/platform/GLFWPlatform.cpp
mac:
	$(CC) -g $(PCH_INCLUDE) ${MAC_DEFINES} ${CFLAGS} $(SRC_FILES) ${MAC_SRC} $(MAC_LIB_DIRS) $(INCLUDE_DIRS) $(LIBS) $(MAC_LIBS) -o output/hello

mac_headers:
	$(CC) -g ${MAC_DEFINES} ${CFLAGS} include/Mojagame/PreCompiledHeaders.hpp $(INCLUDE_DIRS)