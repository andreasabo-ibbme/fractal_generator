#include "Bitmap.hpp"
#include <iostream>

int main()
{
    using namespace asabo;
    asabo::BitMap bm(800, 600);
    bm.write("test2.bmp");
    std::cout << "Finished!\n";
}