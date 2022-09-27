#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <memory>
#include <numeric>
#include <vector>

#include "Bitmap.hpp"
#include "Mandelbrot.hpp"
#include "ZoomList.hpp"

int main()
{
    using namespace asabo;

    constexpr int width{800};
    constexpr int height{600};
    asabo::BitMap bm(width, height);
    asabo::ZoomList zooms(width, height);

    zooms.add(Zoom(width / 2, height / 2, 4.0 / width));
    // zooms.add(Zoom(width/2, height/2, 1));

    double min = std::numeric_limits<double>::max();
    double max = std::numeric_limits<double>::min();

    auto histogram = std::array<int, Mandelbrot::maxIterations>();
    auto histogramCumulative = std::array<int, Mandelbrot::maxIterations + 1>();
    auto fractal = std::vector<int>(width * height, 0);

    // Calculate iterations and build histogram
    for (int y{0}; y < height; ++y) {
        for (int x{0}; x < width; ++x) {
            auto [xFractal, yFractal] = zooms.doZoom(x, y);
            // std::cout << xFractal << " : " << yFractal << '\n';
            // double xFractal = (2.0 * x - width - 200) / height;
            // double yFractal = (y - height / 2.0) / (height / 2.0);

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
            if (iterations != Mandelbrot::maxIterations) {
                histogram[iterations]++;
            }

            fractal[y * width + x] = iterations;

            uint8_t color = (uint8_t) (256 * static_cast<double>(iterations)
                                       / Mandelbrot::maxIterations);
            if (color < min)
                min = color;
            if (color > max)
                max = color;
        }
    }

    auto total = static_cast<double>(width * height);
    // Calculate the cumulative iterations (as fraction)
    for (int i{1}; i < Mandelbrot::maxIterations; ++i) {
        histogramCumulative[i] = (histogramCumulative[i - 1] + histogram[i]);
    }

    // Color the pixels appropriately
    for (int y{0}; y < height; ++y) {
        for (int x{0}; x < width; ++x) {
            auto iterations = fractal[y * width + x];
            auto hue = histogramCumulative[iterations] / total;

            // This does the same as the histogram but O(w*h*maxiterations) overall, histogram is O(maxIteration + w*h)
            // hue = std::accumulate(histogram.cbegin(), histogram.cbegin() + iterations, 0.0) / total;

            uint8_t red{0};
            uint8_t blue{0};
            uint8_t green = std::pow(255, hue);
            bm.setPixel(x, y, red, green, blue);
        }
    }

    bm.write("mandelbrot.bmp");
    std::cout << "Finished!\n";
}