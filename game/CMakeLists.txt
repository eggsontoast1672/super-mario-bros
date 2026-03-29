find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

add_executable(
  smbc
  include/smbc/color.h
  src/game.h
  src/ground.h
  src/player.h
  src/color.c
  src/game.c
  src/ground.c
  src/main.c
  src/player.c
)

target_compile_definitions(smbc PRIVATE ASSET_DIR="${CMAKE_CURRENT_SOURCE_DIR}/../assets/")
target_compile_options(smbc PRIVATE -Wall -Werror -Wextra -Wpedantic)
target_include_directories(smbc PRIVATE include)
target_link_libraries(smbc PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)
