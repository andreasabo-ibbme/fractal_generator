
#include <iostream>

#include "Fractal.hpp"

int main()
{
    using namespace asabo;

    constexpr int width{800};
    constexpr int height{600};
    Fractal fractal{width, height};
    fractal.run("mandbrot_out.bmp");
    std::cout << "Finished!\n";
}