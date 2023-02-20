cmake_minimum_required(VERSION 3.22.1)
project(super-mario-bros)

find_package(PkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)

add_executable(super-mario-bros src/consts.c src/ground.c src/main.c)
target_include_directories(super-mario-bros PRIVATE include)
target_link_libraries(
  super-mario-bros
  ${SDL2_LIBRARIES}
  ${SDL2_IMAGE_LIBRARIES}
)

add_custom_target(run super-mario-bros DEPENDS super-mario-bros)
