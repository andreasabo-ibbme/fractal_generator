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

    SECTION("Add Ranges in increasing order")
    {
        std::vector<size_t> insertOrder{0, 1, 2, 3};
        for (auto i : insertOrder) {
            fractal.addRange(refRanges[i].first, refRanges[i].second);
        }

        auto res = fractal.getRanges();
        REQUIRE(res.size() == refRangesRGB.size());
        for (size_t i{0}; i < res.size(); ++i) {
            CHECK(res[i].colour == refRangesRGB[i]);
        }
    }

    SECTION("Add Ranges in random order")
    {
        std::vector<size_t> insertOrder { 0, 3, 1, 2 };
        for (auto i : insertOrder) {
            fractal.addRange(refRanges[i].first, refRanges[i].second);
        }

        auto res = fractal.getRanges();
        REQUIRE(res.size() == refRangesRGB.size());
        for (size_t i{0}; i < res.size(); ++i) {
            CHECK(res[i].colour == refRangesRGB[i]);
        }
    }
}