
enable_testing()

# GoogleTest
include(FetchContent)
FetchContent_Declare(
    GoogleTest

    # Specify the commit you depend on and update it regularly.
    # URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(GoogleTest)


add_executable(
    hello_test
    hello_test.cc
)

target_link_libraries(
    hello_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)

# target_link_libraries(fractal gtest_main)
# add_test(NAME example_test COMMAND fractal)