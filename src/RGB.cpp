#include "RGB.hpp"

namespace asabo {
RGB operator-(const RGB& first, const RGB& second)
{
    return RGB(first.R + second.R, first.G + second.G, first.B + second.B);
}

} // namespace asabo