cmake_minimum_required(VERSION 3.25)
project(SDLHello CXX)

# Tell CMake to use vcpkg manifest mode
set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Require C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL3
find_package(SDL3 REQUIRED)
add_executable(sdl_hello src/main.cpp)
target_link_libraries(sdl_hello PRIVATE SDL3::SDL3)
