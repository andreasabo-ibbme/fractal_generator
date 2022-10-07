#pragma once
#include "Bitmap.hpp"
#include "Mandelbrot.hpp"
#include "RGB.hpp"
#include "Range.hpp"
#include "ZoomList.hpp"
#include <array>
#include <vector>

namespace asabo {
class Fractal
{
    int m_width;
    int m_height;
    std::unique_ptr<ZoomList> m_zooms;
    std::unique_ptr<BitMap> m_bitMap;
    std::vector<int> m_iterations;
    std::vector<Range> m_ranges;
    std::vector<int> m_rangeTotals;
    std::array<int, Mandelbrot::maxIterations> m_histogram;

public:
    Fractal(int width, int height);
    void run(std::string fileName);
    void addZoom(int x, int y, double scale);
    void addRange(double rangeEnd, const RGB& rgb);

private:
    bool writeFractal(std::string fileName);
    void colourBitmap();
    std::vector<int> buildHistogram();
    void calculatePixelsInRange();
    int getRange(int iterations) const;
};

} // namespace asabo