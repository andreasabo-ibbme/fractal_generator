#pragma once
#include <stdint.h>

// Align on 2 byte boundaries, rather than using extra padding (which may be more efficient)
#pragma pack(2)
namespace asabo {
struct BitmapInfoHeader
{
    int32_t headerSize{40};
    int32_t width;
    int32_t height;
    int16_t planes{1};
    int16_t bitPerPixel{24};
    int32_t compression{0};
    int32_t dataSize{0};
    int32_t horizontalRes{2400};
    int32_t verticalRes{2400};
    int32_t colors{0};
    int32_t importantColors{0};
};
} // namespace asabo