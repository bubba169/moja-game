include common.make

CFLAGS += -g -c -D MG_DESKTOP -D MG_LINUX -D MG_POSIX -D MG_OPENGL
SRC += src/native/platform/GLFWPlatform.cpp
LIB_DIRS += -Llib/linux64
LIBS += -lglfw3 -lGL -lX11 -lXxf86vm -lpthread -lXrandr -ldl -lXinerama -lXcursor
OUTPUT := $(OUTPUT)linux/

default : $(addprefix $(OUTPUT), $(SRC:.cpp=.o))
		g++ -o output/hello $(addprefix $(OUTPUT), $(SRC:.cpp=.o)) $(LIB_DIRS) $(LIBS) 

include $(addprefix $(OUTPUT), $(SRC:.cpp=.d))

$(OUTPUT)%.d : %.cpp
	@[ -d $(@D) ] || mkdir -p $(@D)
	g++ -M -MT $(@:.d=.o) $(CFLAGS) $(INCLUDE_DIRS) $< -o $@

$(OUTPUT)%.o : %.cpp
	@[ -d $(@D) ] || mkdir -p $(@D)
	g++ $(CFLAGS) $(INCLUDE_DIRS) $< -o $@