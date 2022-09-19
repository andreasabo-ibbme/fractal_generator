#include "Bitmap.hpp"
#include "BitmapFileHeader.hpp"
#include "BitmapInfoHeader.hpp"
#include <fstream>
#include <iostream>
using namespace asabo;

namespace asabo {

BitMap::BitMap(int width, int height)
    : m_height(height)
    , m_width(width)
    , m_pPixels(new uint8_t[width * height * 3]())
{}

bool BitMap::write(std::string fileName)
{
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;
    auto dataSize = m_width * m_height * 3;
    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + dataSize;

    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    auto fs = std::ofstream(fileName, std::ios::binary); // Open the file

    if (!fs.is_open()) {
        std::cout << "failed to open the file\n";
        return false;
    }

    // fs.write(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    // fs.write(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
    // fs.write(reinterpret_cast<char*>(m_pPixels.get()), dataSize);
    fs.write((char*)(&fileHeader), sizeof(fileHeader));
    fs.write((char*)(&infoHeader), sizeof(infoHeader));
    fs.write((char*)(m_pPixels.get()), dataSize);

    fs.close();
    return true;
}
void BitMap::setPixel(int x, int y, uint8_t red, uint8_t blue, uint8_t green) {}

} // namespace asabo