cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_VERSION 20)
project(game)

set(GLAD glad.c)
file(GLOB SOURCES src/*.cpp)

add_executable(game ${GLAD} ${SOURCES})
target_link_libraries(game dl glfw3 X11 pthread)
