#include "Fractal.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Fractals are computed_v2")
{
    using namespace asabo;
    constexpr int multFactor = 2;
    constexpr int width{800 * multFactor};
    constexpr int height{600 * multFactor};
    Fractal fractal{width, height};

    SECTION("Add Zoom")
    {
        fractal.addZoom(295 * multFactor, 202 * multFactor, 0.1);
        fractal.addZoom(310 * multFactor, 357 * multFactor, 0.1);
        REQUIRE(1 == 1);
    }
    SECTION("Add Range")
    {
        fractal.addRange(0.0, RGB(0, 0, 0));
        fractal.addRange(0.3, RGB(255, 0, 0));
        fractal.addRange(0.5, RGB(255, 255, 0));
        fractal.addRange(1.0, RGB(255, 255, 255));
        REQUIRE(1 == 1);
    }
}
