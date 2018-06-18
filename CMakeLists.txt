cmake_minimum_required(VERSION 3.11)
project(MoJaGame)

include_directories(include lib/include)

add_definitions(-g -c -std=c++11 -D _USE_MATH_DEFINES -D MG_DESKTOP -D MG_LINUX -D MG_POSIX -D MG_OPENGL -D _USE_MATH_DEFINES -D MG_LIBRARY)
file(GLOB_RECURSE SOURCE src/*.cpp)

link_directories("lib/linux64/")

add_library(mojagame ${SOURCE})
add_executable(test1 test/SimpleImage/Main.cpp)

#add_library(glfw STATIC IMPORTED)
if (APPLE)
    message("Building for MAC")
endif (APPLE)

if (UNIX)
    message("Building for UNIX")

    find_library(X11_LIB X11)
    find_library(XXF86VM_LIB Xxf86vm)
    find_library(PTHREAD_LIB pthread)
    find_library(XRANDR_LIB Xrandr)
    find_library(XINERAMA_LIB Xinerama)
    find_library(XCURSOR_LIB Xcursor)
    target_link_libraries(test1 ${X11_LIB} ${XXF86VM_LIB} ${PTHREAD_LIB} ${XRANDR_LIB} ${XINERAMA_LIB} ${XCURSOR_LIB} glfw3)
endif (UNIX)

find_library(GL_LIB OpenGL)
target_link_libraries(test1 ${GL_LIB})

target_link_libraries(test1 mojagame)