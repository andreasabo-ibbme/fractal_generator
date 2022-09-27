cmake_minimum_required(VERSION 3.16)
project(fractal VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-Wall -Wextra -Wpedantic)

include(CTest)
enable_testing()

include_directories(include)
add_executable(fractal
    src/main.cpp
    src/BitMap.cpp
    src/Mandelbrot.cpp
    src/ZoomList.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
