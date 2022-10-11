#include "Fractal.hpp"
#include "RGB.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Fractals interface")
{
    using namespace asabo;
    constexpr int multFactor = 2;
    constexpr int width{800 * multFactor};
    constexpr int height{600 * multFactor};
    Fractal fractal{width, height};

    auto rgb1 = RGB(0, 0, 0);
    auto rgb2 = RGB(255, 0, 0);
    auto rgb3 = RGB(255, 255, 0);
    auto rgb4 = RGB(255, 255, 255);

    // Expected order
    std::vector<RGB> refRangesRGB{rgb1, rgb2, rgb3, rgb4};
    std::vector<double> refRangesStart{0.0, 0.3, 0.5, 1.0};
    std::vector<std::pair<double, RGB>> refRanges;
    for (size_t i{0}; i < refRangesRGB.size(); ++i) {
        refRanges.push_back({refRangesStart[i], refRangesRGB[i]});
    }

    SECTION("No ranges")
    {
        auto res = fractal.getRanges();
        REQUIRE(res.size() == 0);
    }

    SECTION("One range")
    {
        fractal.addRange(refRanges[0].first, refRanges[0].second);
        auto res = fractal.getRanges();

        REQUIRE(res.size() == 1);
        CHECK(res[0].colour == refRanges[0].second);
    }
    SECTION("Add Ranges in various orders")
    {
        std::vector<size_t> insertOrder;

        SECTION("in order") { insertOrder = {0, 1, 2, 3}; }

        SECTION("out of order") { insertOrder = {0, 3, 2, 1}; }

        for (auto i : insertOrder) {
            fractal.addRange(refRanges[i].first, refRanges[i].second);
        }

        auto res = fractal.getRanges();
        REQUIRE(res.size() == refRangesRGB.size());
        for (size_t i{0}; i < res.size(); ++i) {
            CHECK(res[i].colour == refRanges[i].second);
        }
    }
}
