
#include <iostream>

#include "Fractal.hpp"

int main()
{
    using namespace asabo;
    constexpr int multFactor = 2;
    constexpr int width{800 * multFactor};
    constexpr int height{600 * multFactor};
    Fractal fractal{width, height};
    fractal.addZoom(295 * multFactor, 202 * multFactor, 0.1);
    fractal.addZoom(310 * multFactor, 357 * multFactor, 0.1);
    fractal.run("mandbrot_out4.bmp");
    std::cout << "Finished!\n";
}