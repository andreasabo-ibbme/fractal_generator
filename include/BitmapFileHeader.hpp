#pragma once
#include <stdint.h>

// Align on 2 byte boundaries, rather than using extra padding (which may be more efficient)
#pragma pack(push, 2)

namespace asabo {
struct BitmapFileHeader
{
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};
#pragma pack(pop)
} // namespace asabo