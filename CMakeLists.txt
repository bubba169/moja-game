cmake_minimum_required(VERSION 3.11)
project(MoJaGame)

include_directories(include lib/include)

add_definitions(-v -std=c++11 -D MG_DESKTOP -D MG_LINUX -D MG_POSIX -D MG_OPENGL -D _USE_MATH_DEFINES -D MG_LIBRARY)
file(GLOB_RECURSE SOURCE src/*.cpp)

add_library(mojagame ${SOURCE})
add_executable(test1 test/SimpleImage/Main.cpp)

if (APPLE)
    message("Building for MAC")
    link_directories(lib/mac64)
    find_library(GL_LIB OpenGL)
endif (APPLE)

if (LINUX)
    message("Building for LINUX")
    link_directories(lib/linux64)
    find_library(GL_LIB OpenGL)
endif (LINUX)

#find_library(GLFW_LIB libglfw3 lib/mac64)

#target_link_libraries(mojagame libglfw3.a)
target_link_libraries(test1 mojagame)
target_link_libraries(test1 ${GL_LIB} glfw3)