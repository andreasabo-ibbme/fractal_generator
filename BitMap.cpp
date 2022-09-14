#include "Bitmap.hpp"

namespace asabo {

BitMap::BitMap(int width, int height)
    : m_height(height)
    , m_width(width)
    , m_pPixels(new uint8_t[width * height * 3])
{}

bool BitMap::write(std::string fileName) {}
void BitMap::setPixel(int x, int y, uint8_t red, uint8_t blue, uint8_t green) {}
} // namespace asabo