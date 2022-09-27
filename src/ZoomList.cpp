#include "ZoomList.hpp"

namespace asabo {
ZoomList::ZoomList(int width, int height)
    : m_width(width)
    , m_height(height)
{}

void ZoomList::add(const Zoom& zoom)
{
    m_zooms.push_back(zoom);
    m_xCenter += (zoom.x - m_width / 2) * m_scale;
    m_yCenter += (zoom.y - m_height / 2) * m_scale;

    m_scale *= zoom.scale;
}

std::pair<double, double> ZoomList::doZoom(int x, int y)
{
    auto xFractal = (x - m_width / 2) * m_scale + m_xCenter;
    auto yFractal = (y - m_height / 2) * m_scale + m_yCenter;

    return std::make_pair(xFractal, yFractal);
}
} // namespace asabo