#include <cstdint>
#include <iostream>
#include <limits>

#include "Bitmap.hpp"
#include "Mandelbrot.hpp"

int main()
{
    using namespace asabo;

    constexpr int width{800};
    constexpr int height{600};
    asabo::BitMap bm(width, height);

    double min = std::numeric_limits<double>::max();
    double max = std::numeric_limits<double>::min();

    for (int y{0}; y < height; ++y) {
        for (int x{0}; x < width; ++x) {
            double xFractal = (2.0 * x - width) / width;
            double yFractal = (y - height / 2.0) / (height / 2.0);

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            uint8_t color = (uint8_t) (256 * static_cast<double>(iterations)
                                       / Mandelbrot::maxIterations);
            color = color * color * color;
            bm.setPixel(x, y, 0, color, 0);
            if (color < min)
                min = color;
            if (color > max)
                max = color;
        }
    }

    std::cout << min << " : " << max << '\n';

    // bm.setPixel(width / 2, height / 2, 255, 255, 255);
    bm.write("mandelbrot.bmp");
    std::cout << "Finished!\n";
}