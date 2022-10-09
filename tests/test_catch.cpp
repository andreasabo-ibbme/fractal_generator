#define CONFIG_CATCH_MAIN
#include <catch2/catch_test_macros.hpp>
#include "Fractal.hpp"
// #include <catch2/catch_test_macros.hpp>

unsigned int Factorial(unsigned int number)
{
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Fractals are computed")
{
    using namespace asabo;
    constexpr int multFactor = 2;
    constexpr int width{800 * multFactor};
    constexpr int height{600 * multFactor};
    Fractal fractal{width, height};
    // fractal.addZoom(295 * multFactor, 202 * multFactor, 0.1);
    // fractal.addZoom(310 * multFactor, 357 * multFactor, 0.1);
    REQUIRE(1 == 1);
    // SECTION("Add Zoom") { REQUIRE(1 == 1); }
    // SECTION("Add Range")
    // {
    //     fractal.addRange(0.0, RGB(0, 0, 0));
    //     fractal.addRange(0.3, RGB(255, 0, 0));
    //     fractal.addRange(0.5, RGB(255, 255, 0));
    //     fractal.addRange(1.0, RGB(255, 255, 255));
    // }
}

TEST_CASE("Factorials are computed", "[factorial]")
{
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}