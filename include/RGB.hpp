#pragma once
#include <iostream>

namespace asabo {
struct RGB
{
    double R;
    double G;
    double B;

    RGB(double r, double g, double b) : R(r), G(g), B(b) {}
    friend std::ostream& operator<<(std::ostream& os, const RGB& obj);
};
RGB operator-(const RGB& first, const RGB& second);
RGB operator+(const RGB& first, const RGB& second);
bool operator==(const RGB& first, const RGB& second);
} // namespace asabo