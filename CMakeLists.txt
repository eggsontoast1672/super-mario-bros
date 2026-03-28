cmake_minimum_required(VERSION 3.22.1)

project(SuperMarioBros)

set(CMAKE_C_STANDARD 90)

find_package(PkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)

add_executable(
  smb
  src/game.h
  src/ground.h
  src/player.h
  src/game.c
  src/ground.c
  src/main.c
  src/player.c
)

target_compile_definitions(smb PRIVATE ASSET_DIR="${CMAKE_CURRENT_SOURCE_DIR}/images/")
target_compile_options(smb PRIVATE -Wall -Werror -Wextra -Wpedantic)
target_include_directories(smb PRIVATE include)
target_link_libraries(smb PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
