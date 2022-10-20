#include "RGB.hpp"

#include <algorithm>
namespace asabo {

RGB::RGB(double r, double g, double b) : R(r), G(g), B(b)
{
    clipRGB();
}

void RGB::clipRGB()
{
    R = clipToRange(R);
    G = clipToRange(G);
    B = clipToRange(B);
}

double RGB::clipToRange(double input) const
{
    return std::clamp(input, lo, hi);
}

RGB operator-(const RGB& first, const RGB& second)
{
    auto ret = RGB(first.R - second.R, first.G - second.G, first.B - second.B);
    ret.clipRGB();
    return ret;
}
RGB operator+(const RGB& first, const RGB& second)
{
    auto ret = RGB(first.R + second.R, first.G + second.G, first.B + second.B);
    ret.clipRGB();
    return ret;
}

bool operator==(const RGB& first, const RGB& second)
{
    return first.R == second.R && first.G == second.G && first.B == second.B;
}

std::ostream& operator<<(std::ostream& os, const RGB& obj)
{
    os << "R:" << obj.R << " G:" << obj.G << " B:" << obj.B << '\n';
    return os;
}
} // namespace asabo