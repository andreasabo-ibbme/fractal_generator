
enable_testing()

add_executable(tests test_catch.cpp)
include(Catch)
# target_include_directorie())
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
# target_link_libraries(tests PRIVATE Catch2::Catch2)
# target_link_libraries(tests fractal)
catch_discover_tests(tests)