
enable_testing()

add_executable(tests test_catch.cpp)
include(Catch)
target_link_libraries(tests PRIVATE fractal_lib Catch2::Catch2WithMain)
catch_discover_tests(tests)