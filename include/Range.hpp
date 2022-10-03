#pragma once

#include "RGB.hpp"

namespace asabo {
struct Range
{
    int rangeEnd;
    RGB colour;
    Range(int rangeEnd, RGB colour) : rangeEnd(rangeEnd), colour(colour) {}
    bool operator<(const Range& other) const { return rangeEnd < other.rangeEnd; }
};

} // namespace asabo
