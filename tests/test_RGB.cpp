#include "RGB.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("RGB class")
{
    using namespace asabo;
    auto rgb1 = RGB(200, 210, 220);
    auto rgb2 = RGB(45, 35, 25);
    auto rgb3 = RGB(100, 110, 120);
    constexpr int lo{0};
    constexpr int hi{255};

    SECTION("Below zero value")
    {
        auto res = RGB(-10, -10, -10);
        REQUIRE(res.R == lo);
        REQUIRE(res.G == lo);
        REQUIRE(res.B == lo);
    }

    SECTION("Above max value")
    {
        auto res = RGB(1234, 2345, 253);
        REQUIRE(res.R == hi);
        REQUIRE(res.G == hi);
        REQUIRE(res.B == 253);
    }

    SECTION("Mix above and below range")
    {
        auto res = RGB(-123, 245, 2521);
        REQUIRE(res.R == lo);
        REQUIRE(res.G == 245);
        REQUIRE(res.B == 255);
    }

    SECTION("Arithmetic in range")
    {
        auto resPlus = rgb2 + rgb3;
        REQUIRE(resPlus.R == 145);
        REQUIRE(resPlus.G == 145);
        REQUIRE(resPlus.B == 145);

        auto resMinus = rgb3 - rgb2;
        REQUIRE(resMinus.R == 55);
        REQUIRE(resMinus.G == 75);
        REQUIRE(resMinus.B == 95);
    }

    SECTION("Arithmetic out of range")
    {
        auto resPlus = rgb1 + rgb3;
        REQUIRE(resPlus.R == hi);
        REQUIRE(resPlus.G == hi);
        REQUIRE(resPlus.B == hi);

        auto resMinus = rgb2 - rgb2;
        REQUIRE(resMinus.R == lo);
        REQUIRE(resMinus.G == lo);
        REQUIRE(resMinus.B == lo);
    }
}
