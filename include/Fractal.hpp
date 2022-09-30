#pragma once
#include "Bitmap.hpp"
#include "ZoomList.hpp"

namespace asabo {

class Fractal
{
    int m_width;
    int m_height;
    std::unique_ptr<ZoomList> m_zooms;
    std::unique_ptr<BitMap> m_bitMap;
    std::vector<int> m_iterations;



public:
    Fractal(int width, int height);
    void run(std::string fileName);
private:
    bool writeFractal(std::string fileName);
    void addZoom(int x, int y, double scale);
    void colourBitmap();
    std::vector<int> buildHistogram();
};

} // namespace asabo