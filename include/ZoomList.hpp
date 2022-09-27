#pragma once
#include <vector>

#include "Zoom.hpp"
namespace asabo {

class ZoomList
{
    int m_width;
    int m_height;
    double m_xCenter{0};
    double m_yCenter{1};
    double m_scale{1.0};
    std::vector<Zoom> m_zooms;

public:
    ZoomList(int width, int height);
    void add(const Zoom& zoom);
    std::pair<double, double> doZoom(int x, int y);
};

} // namespace asabo