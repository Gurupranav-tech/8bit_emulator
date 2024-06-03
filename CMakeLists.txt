cmake_minimum_required(VERSION 3.1)

project(8bit)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB source_files CONFIGURE_DEPENDS "./src/*.cpp" "./src/**/*.cpp")

add_executable(8bit ${source_files})

target_include_directories(8bit PUBLIC "./src/include")
target_include_directories(8bit PUBLIC "./spdlog/include")
target_include_directories(8bit PUBLIC "./spdlog")
target_include_directories(8bit PUBLIC "./raylib/src")

add_subdirectory("./raylib")

target_link_libraries(8bit PUBLIC "raylib")
target_precompile_headers(8bit PUBLIC "./src/include/pch.hpp")