
enable_testing()

add_executable(tests test_catch.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
include(Catch)
catch_discover_tests(tests)