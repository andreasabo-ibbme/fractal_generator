#pragma once

namespace asabo {

struct Zoom
{
    int x{0};
    int y{0};
    double scale{1.0};
    Zoom(int x, int y, double scale)
        : x(x)
        , y(y)
        , scale(scale)
    {}


};

} // namespace asabo