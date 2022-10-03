#include "Fractal.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>

using namespace asabo;

Fractal::Fractal(int width, int height) : m_width(width), m_height(height)
{
    m_bitMap = std::make_unique<BitMap>(m_width, m_height);
    m_zooms = std::make_unique<ZoomList>(ZoomList(m_width, m_height));
    m_iterations.resize(width * height);
    addZoom(m_width / 2, m_height / 2, 4.0 / m_width);
}

void Fractal::run(std::string fileName)
{
    colourBitmap();
    writeFractal(fileName);
}

bool Fractal::writeFractal(std::string fileName)
{
    return m_bitMap->write(fileName);
}

void Fractal::addZoom(int x, int y, double scale)
{
    m_zooms->add(Zoom(x, y, scale));
}

void Fractal::addRange(double rangeEnd, const RGB& rgb)
{
    m_ranges.emplace_back(rangeEnd * Mandelbrot::maxIterations, rgb);
}

void Fractal::colourBitmap()
{
    auto cumulativeIterHistogram = buildHistogram();
    auto total = static_cast<double>(m_width * m_height);
    for (int y{0}; y < m_height; ++y) {
        for (int x{0}; x < m_width; ++x) {
            auto iterations = m_iterations[y * m_width + x];
            auto hue = cumulativeIterHistogram[iterations] / total;
            // This does the same as the histogram but O(w*h*maxiterations) overall, histogram is O(maxIteration + w*h)
            // hue = std::accumulate(histogram.cbegin(), histogram.cbegin() + iterations, 0.0) / total;

            uint8_t red{0};
            uint8_t blue{0};
            uint8_t green = std::pow(255, hue);
            m_bitMap->setPixel(x, y, red, green, blue);
        }
    }
}

/* PRIVATE */
std::vector<int> Fractal::buildHistogram()
{
    // auto histogram = std::array<int, Mandelbrot::maxIterations>();
    m_histogram.fill(0);
    auto histogramCumulative = std::vector<int>(Mandelbrot::maxIterations + 1);
    for (int y{0}; y < m_height; ++y) {
        for (int x{0}; x < m_width; ++x) {
            auto [xFractal, yFractal] = m_zooms->doZoom(x, y);
            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
            if (iterations != Mandelbrot::maxIterations) {
                m_histogram[iterations]++;
            }
            m_iterations[y * m_width + x] = iterations;
        }
    }

    // Calculate the cumulative iterations (as fraction)
    for (int i{1}; i < Mandelbrot::maxIterations; ++i) {
        histogramCumulative[i] = (histogramCumulative[i - 1] + m_histogram[i]);
    }
    calculatePixelsInRange();
    return histogramCumulative;
}

std::vector<int> Fractal::calculatePixelsInRange()
{
    std::sort(m_ranges.begin(), m_ranges.end()); // Sort by rangeEnd cutoffs
    std::vector<int> rangeTotal(m_ranges.size() - 1, 0);
    for (int i{0}; i < int(m_ranges.size()) - 1; ++i) {
        auto startIter = m_ranges[i].rangeEnd;
        auto endIter = m_ranges[i + 1].rangeEnd;
        rangeTotal[i] = std::accumulate(m_histogram.begin() + startIter, m_histogram.begin() + endIter, 0);
    }

    return rangeTotal;
}
