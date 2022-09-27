
#include <iostream>

#include "Fractal.hpp"

int main()
{
    using namespace asabo;

    constexpr int width{800};
    constexpr int height{600};
    Fractal fractal{width, height};
    fractal.addZoom(width / 2, height / 2, 4.0 / width);
    fractal.colourBitmap();

    fractal.writeFractal("mandelbrot.bmp");
    std::cout << "Finished!\n";
}