find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

add_library(
  smbc-core
  include/smbc-core/assets.hpp
  include/smbc-core/level.hpp
  src/assets.cpp
  src/level.cpp
)

# set_property(TARGET smbc-core PROPERTY CXX_STANDARD 23)
# set_property(TARGET smbc-core PROPERTY CXX_STANDARD_REQUIRED ON)
# set_property(TARGET smbc-core PROPERTY CXX_EXTENSIONS OFF)

target_compile_definitions(smbc-core PRIVATE ASSET_PATH="${CMAKE_CURRENT_SOURCE_DIR}/../")
target_include_directories(smbc-core PUBLIC include)
target_link_libraries(smbc-core PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)
