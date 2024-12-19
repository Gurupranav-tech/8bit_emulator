cmake_minimum_required(VERSION 3.22)
project(8bit)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "./src/*.cpp" "./src/emulator/**/*.cpp" )

add_executable(8bit ${SOURCE_FILES})

add_subdirectory("vendor/raylib")
add_subdirectory("vendor/spdlog")

target_precompile_headers(8bit PUBLIC "./src/emulator/config.hpp")

target_include_directories(8bit PUBLIC "./src")
target_include_directories(8bit PUBLIC "./vendor/raylib/src")
target_include_directories(8bit PUBLIC "./vendor/spdlog/include")

target_link_libraries(8bit PUBLIC raylib)
