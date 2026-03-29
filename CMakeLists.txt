cmake_minimum_required(VERSION 3.20)

project(SuperMarioBrosClone LANGUAGES C CXX)

# TODO: Remove all of this C stuff
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Werror -Wextra -Wpedantic)

add_subdirectory(core)
add_subdirectory(editor)
add_subdirectory(game)
