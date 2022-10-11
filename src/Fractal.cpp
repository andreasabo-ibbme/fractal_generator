#include "Fractal.hpp"

#include <algorithm>
#include <cassert>
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

void Fractal::addRange(double rangeEnd, const RGB& rgb)
{
    m_ranges.emplace_back(rangeEnd * Mandelbrot::maxIterations, rgb);
    std::sort(m_ranges.begin(), m_ranges.end());
}

void Fractal::addZoom(int x, int y, double scale)
{
    m_zooms->add(Zoom(x, y, scale));
}

std::vector<Range> Fractal::getRanges() const
{
    return m_ranges;
}

void Fractal::colourBitmap()
{
    auto cumulativeIterHistogram = buildHistogram();
    for (int y{0}; y < m_height; ++y) {
        for (int x{0}; x < m_width; ++x) {
            auto iterations = m_iterations[y * m_width + x];
            auto rangeInd = getRange(iterations);

            auto rangeStartIter = m_ranges[rangeInd].rangeEnd;

            auto startColour = m_ranges[rangeInd].colour;
            auto endColour = m_ranges[rangeInd + 1].colour;
            auto colourDiff = endColour - startColour;

            auto rangeTotal = m_rangeTotals[rangeInd];
            // Total up all pixels up to this number of iterations starting from the beginning of the current range,
            // Divided by all of the pixels in this range
            auto uptoIterInRange = std::accumulate(m_histogram.cbegin() + rangeStartIter,
                                                   m_histogram.cbegin() + iterations,
                                                   0.0);
            // This does the same as the histogram but O(w*h*maxiterations) overall, histogram is O(maxIteration + w*h)
            // hue = std::accumulate(histogram.cbegin(), histogram.cbegin() + iterations, 0.0) / total;
            double inRangeFraction = uptoIterInRange / static_cast<double>(rangeTotal);
            uint8_t red = startColour.R + colourDiff.R * inRangeFraction;
            uint8_t green = startColour.G + colourDiff.G * inRangeFraction;
            uint8_t blue = startColour.B + colourDiff.B * inRangeFraction;
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

void Fractal::calculatePixelsInRange()
{
    std::sort(m_ranges.begin(), m_ranges.end()); // Sort by rangeEnd cutoffs
    // std::vector<int> m_range_totals(m_ranges.size() - 1, 0);
    m_rangeTotals.resize(m_ranges.size() - 1, 0);
    for (int i{0}; i < int(m_ranges.size()) - 1; ++i) {
        auto startIter = m_ranges[i].rangeEnd;
        auto endIter = m_ranges[i + 1].rangeEnd;
        m_rangeTotals[i] = std::accumulate(m_histogram.begin() + startIter, m_histogram.begin() + endIter, 0);
    }
}

int Fractal::getRange(int iterations) const
{
    int rangeInd = 0;
    while (rangeInd < static_cast<int>(m_ranges.size()) - 1) {
        if (m_ranges[rangeInd + 1].rangeEnd > iterations) {
            break;
        }
        rangeInd++;
    }
    // If the ranges aren't defined fully or correctly, the rangeInd may be invalid
    assert(rangeInd > -1);
    assert(rangeInd < static_cast<int>(m_ranges.size()));
    return rangeInd;
}
