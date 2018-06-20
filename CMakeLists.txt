cmake_minimum_required(VERSION 3.11)
project(MoJaGame)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

include_directories(include lib/include)

add_definitions(-g -c -std=c++11 -D _USE_MATH_DEFINES -D MG_LIBRARY)
file(GLOB_RECURSE SOURCE src/*.cpp)

if (APPLE)
    message("Building for MAC")
    link_directories("lib/mac64/")

    find_library(COCOA_LIB Cocoa)
    find_library(COREVIDEO_LIB CoreVideo)
    find_library(IOKIT_LIB IOKit)
    set(PLATFORM_LIBS ${COCOA_LIB} ${COREVIDEO_LIB} ${IOKIT_LIB})

    add_definitions(-D MG_DESKTOP -D MG_POSIX -D MG_OPENGL -D MG_MACOS)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib/mac64)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib/mac64)

else (UNIX)
    message("Building for UNIX")
    link_directories("lib/linux64/")

    find_library(X11_LIB X11)
    find_library(XXF86VM_LIB Xxf86vm)
    find_library(PTHREAD_LIB pthread)
    find_library(XRANDR_LIB Xrandr)
    find_library(XINERAMA_LIB Xinerama)
    find_library(XCURSOR_LIB Xcursor)
    find_library(DL_LIB dl)
    set(PLATFORM_LIBS ${X11_LIB} ${XXF86VM_LIB} ${PTHREAD_LIB} ${XRANDR_LIB} ${XINERAMA_LIB} ${XCURSOR_LIB} ${DL_LIB})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib/linux64)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib/linux64)

    add_definitions(-D MG_DESKTOP -D MG_POSIX -D MG_OPENGL -D MG_LINUX)

endif (APPLE)

add_library(mojagame ${SOURCE})
add_executable(test test/SimpleImage/Main.cpp)

find_library(GL_LIB OpenGL)
target_link_libraries(test mojagame glfw3 ${GL_LIB} ${PLATFORM_LIBS})