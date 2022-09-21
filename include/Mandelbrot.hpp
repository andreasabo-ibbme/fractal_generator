#pragma once

namespace asabo {

class Mandelbrot
{
public:
    static constexpr int maxIterations{1000};

public:
    Mandelbrot();
    static int getIterations(double x, double y);
};
} // namespace asabo