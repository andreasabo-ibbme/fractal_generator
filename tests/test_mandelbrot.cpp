#include "Mandelbrot.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("Mandelbrot calculator")
{
    using namespace asabo;

    SECTION("Origin")
    {
        auto res = Mandelbrot::getIterations(0, 0);
        REQUIRE(res == Mandelbrot::maxIterations);
    }

    SECTION("Small real positive - 0.05")
    {
        auto res = Mandelbrot::getIterations(0.05, 0);
        REQUIRE(res == Mandelbrot::maxIterations);
    }

    SECTION("Small real positive - 0.5")
    {
        auto res = Mandelbrot::getIterations(0.5, 0);
        REQUIRE(res == 4);
    }

    SECTION("Large real positive")
    {
        auto res = Mandelbrot::getIterations(1.5, 0);
        REQUIRE(res == 1);
    }

    SECTION("Small imag positive - 0.05")
    {
        auto res = Mandelbrot::getIterations(0, 0.05);
        REQUIRE(res == Mandelbrot::maxIterations);
    }

    SECTION("Small imag positive - 0.5")
    {
        auto res = Mandelbrot::getIterations(0, 0.5);
        REQUIRE(res == Mandelbrot::maxIterations);
    }

    SECTION("Small real negative - 1.0")
    {
        auto res = Mandelbrot::getIterations(1.0, 0);
        REQUIRE(res == 2);
    }

    SECTION("Large imag positive")
    {
        auto res = Mandelbrot::getIterations(0, 1.5);
        REQUIRE(res == 1);
    }

    SECTION("Large imag negative - -1.5")
    {
        auto res = Mandelbrot::getIterations(0, -1.5);
        REQUIRE(res == 1);
    }

    SECTION("Large imag negative - -1.0")
    {
        auto res = Mandelbrot::getIterations(0, -1.5);
        REQUIRE(res == 1);
    }

    SECTION("Real + Img - (0.32, 0.587)")
    {
        auto res = Mandelbrot::getIterations(0.32, 0.587);
        REQUIRE(res == 23);
    }

    SECTION("Real + Img - (0.312, 0.587)")
    {
        auto res = Mandelbrot::getIterations(0.312, 0.587);
        REQUIRE(res == 18);
    }

    SECTION("Real + Img - (0.312, -0.587)")
    {
        auto res = Mandelbrot::getIterations(0.312, -0.587);
        REQUIRE(res == 18);
    }

    SECTION("Real + Img - (0.312, -0.57)")
    {
        auto res = Mandelbrot::getIterations(0.312, -0.57);
        REQUIRE(res == 59);
    }

    SECTION("Real + Img - (0.376, -0.678)")
    {
        auto res = Mandelbrot::getIterations(0.376, -0.678);
        REQUIRE(res == 27);
    }
}
