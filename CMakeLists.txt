cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_VERSION 20)
project(game)

set(GLAD glad.c)
file(GLOB_RECURSE GAME_SOURCES src/*.cpp)
file(GLOB_RECURSE ENGINE Engine/*.cpp)
set(ENGINE_PCH Engine/Utils/enginePch.hpp)

add_executable(game ${GLAD} ${ENGINE_PCH} ${ENGINE} ${GAME_SOURCES})
target_link_libraries(game dl glfw3 X11 pthread)
target_include_directories(game PRIVATE Engine/include)
