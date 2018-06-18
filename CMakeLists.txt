cmake_minimum_required(VERSION 3.11)
project(MoJaGame)

include_directories(include lib/include)
link_directories(lib/linux64)

add_definitions(-D MG_DESKTOP -D MG_LINUX -D MG_POSIX -D MG_OPENGL)
file(GLOB_RECURSE SOURCE src/*.cpp)

add_library(mojagame ${SOURCE})
target_link_libraries(mojagame glfw3)

add_executable(test1 test/SimpleImage/Main.cpp)
target_link_libraries(test1 mojagame)