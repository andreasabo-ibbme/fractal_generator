#include "Zoom.hpp"
#include "ZoomList.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("Zoom and ZoomList class")
{
    using namespace asabo;
    constexpr int width{2000};
    constexpr int height{1000};
    ZoomList refZoomList(width, height);

    SECTION("One Zoom")
    {
        refZoomList.add(Zoom{1000, 500, 2.0});
        SECTION("Checking center")
        {
            // Center should be at 0,0
            auto [x, y] = refZoomList.doZoom(width / 2, height / 2);
            REQUIRE(x == 0);
            REQUIRE(y == 0);
        }

        SECTION("Checking top-left corner")
        {
            auto [x, y] = refZoomList.doZoom(0, 0);
            REQUIRE(x == -2000);
            REQUIRE(y == -1000);
        }

        SECTION("Checking bottom-right corner")
        {
            auto [x, y] = refZoomList.doZoom(width, height);
            REQUIRE(x == 2000);
            REQUIRE(y == 1000);
        }
    }

SECTION("Two Zooms")
    {
        refZoomList.add(Zoom{1000, 500, 2.0});
        refZoomList.add(Zoom{500, 250, 2.0});

        SECTION("Checking center")
        {
            auto [x, y] = refZoomList.doZoom(width / 2, height / 2);
            REQUIRE(x == -1000);
            REQUIRE(y == -500);
        }

        SECTION("Checking top-left corner")
        {
            auto [x, y] = refZoomList.doZoom(0, 0);
            REQUIRE(x == -5000);
            REQUIRE(y == -2500);
        }

        SECTION("Checking bottom-right corner")
        {
            auto [x, y] = refZoomList.doZoom(width, height);
            REQUIRE(x == 3000);
            REQUIRE(y == 1500);
        }
    }
}
