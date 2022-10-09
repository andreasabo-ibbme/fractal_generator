# https://stackoverflow.com/questions/70667511/how-can-i-make-my-first-test-with-catch-for-my-qt-application
set(lib_SRC
    BitMap.cpp
    Fractal.cpp
    Mandelbrot.cpp
    RGB.cpp
    ZoomList.cpp
)
add_library(fractal_lib STATIC ${lib_SRC})

add_executable(fractal main.cpp)
target_link_libraries(fractal fractal_lib)