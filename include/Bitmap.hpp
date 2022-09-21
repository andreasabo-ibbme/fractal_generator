#pragma once
#include <memory>
#include <stdint.h>
#include <string>

namespace asabo {

class BitMap
{
private:
    int m_height{0};
    int m_width{0};
    std::unique_ptr<uint8_t[]> m_pPixels{nullptr};

public:
    BitMap(int width, int height);
    bool write(std::string fileName);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
};
} // namespace asabo
