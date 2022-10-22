cmake_minimum_required(VERSION 3.16)
project(fractal VERSION 0.1.0)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-Wall -Wextra -Wpedantic)

include(CTest)
include(CPack)

include_directories(include)
add_subdirectory(src)

# Installation
if(NOT DEFINED INSTALL_DIR)
    set(INSTALL_DIR "bin")
endif()

install(TARGETS fractal
    DESTINATION "${INSTALL_DIR}"
)

# Testing
option(BUILD_TESTING "Build the tests" ON)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(extern/Catch2)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
    add_subdirectory(tests)
    install(TARGETS tests
        DESTINATION "${INSTALL_DIR}"
    )
endif()
