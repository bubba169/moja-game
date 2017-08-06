##
# CONFIG
##

CFLAGS=-std=c++11
LIBS=
LIB_DIRS=
INCLUDE_DIRS=-Iinclude -Ilib/include
SRC = $(wildcard src/*.cpp) $(wildcard src/assets/*.cpp) $(wildcard src/math/*.cpp)

##
# LINUX
##

LINUX_CFLAGS = $(CFLAGS) -g -c -D DESKTOP -D LINUX -D GLFW_INCLUDE_ES2
LINUX_SRC = $(SRC) src/native/platform/GLFWPlatform.cpp
LINUX_LIB_DIRS = $(LIB_DIRS) -Llib/linux64
LINUX_LIBS = $(LIBS) -lglfw3 -lGL -lX11 -lXxf86vm -lpthread -lXrandr -ldl -lXinerama -lXcursor
LINUX_OUTPUT = output/objects/linux/

$(LINUX_OUTPUT)%.o : %.cpp
	@[ -d $(@D) ] || mkdir -p $(@D)
	g++ $(LINUX_CFLAGS) $(INCLUDE_DIRS) $< -o $@

linux : $(addprefix $(LINUX_OUTPUT), $(LINUX_SRC:.cpp=.o))
	g++ -o output/hello $(addprefix $(LINUX_OUTPUT), $(LINUX_SRC:.cpp=.o)) $(LINUX_LIB_DIRS) $(LINUX_LIBS) 

##
# MAC
##

MAC_CFLAGS = -D DESKTOP -D MACOS -D GLFW_INCLUDE_ES2
MAC_SRC_FILES = $(SRC) src/native/platform/GLFWPlatform.cpp
MAC_LIB_DIRS = -Llib/mac64
MAC_LIBS = $(LIBS) -lglfw3 -framework OpenGL -framework Cocoa -framework CoreVideo -framework IOKit
MAC_OUTPUT = output/objects/mac/

$(MAC_OUTPUT)%.o : %.cpp
	@[ -d $(@D) ] || mkdir -p $(@D)
	g++ $(MAC_CFLAGS) $(INCLUDE_DIRS) $< -o $@

mac : $(addprefix $(MAC_OUTPUT), $(MAC_SRC:.cpp=.o))
	g++ -o output/hello $(addprefix $(MAC_OUTPUT), $(MAC_SRC:.cpp=.o)) $(MAC_LIB_DIRS) $(MAC_LIBS) 