#pragma once
#include <iostream>

namespace asabo {
struct RGB
{
    double R;
    double G;
    double B;

    RGB(double r, double g, double b);
    friend std::ostream& operator<<(std::ostream& os, const RGB& obj);
    void clipRGB();

private:
    double lo{0};
    double hi{255};
    double clipToRange(double input) const;
};
RGB operator-(const RGB& first, const RGB& second);
RGB operator+(const RGB& first, const RGB& second);
bool operator==(const RGB& first, const RGB& second);
} // namespace asabo