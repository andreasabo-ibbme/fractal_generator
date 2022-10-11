#include "RGB.hpp"
namespace asabo {
RGB operator-(const RGB& first, const RGB& second)
{
    return RGB(first.R - second.R, first.G - second.G, first.B - second.B);
}
RGB operator+(const RGB& first, const RGB& second)
{
    return RGB(first.R + second.R, first.G + second.G, first.B + second.B);
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