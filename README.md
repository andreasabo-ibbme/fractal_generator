# Fractal Generator

This project provides a simple Mandelbrot set (https://en.wikipedia.org/wiki/Mandelbrot_set) visualizer that generates a bitmap visualization of the number of iterations to divergence. 

The number of iterations is calculated by iterating $z_{n+1} = z_n^2+ c$ starting at each point $c$ on the complex plane and counting the first iteration when the magnitude exceeds 2. 

![Mandelbrot](./mandelbrot.bmp)

## Cloning
This repo includes Catch2 as a submodule, so this repo should be cloned with:

```
git clone --recursive https://github.com/andreasabo-ibbme/fractal_generator.git
```

Alternatively:
```
git clone https://github.com/andreasabo-ibbme/fractal_generator.git
git submodule update --init
```

## Building and Installation
These instructions have been tested on Windows 10 Home build 19044.1586, GCC 10.3.0

```
# Configure the library
cmake -S . -B build -G Ninja      # You can select your preferred generator

# Build and install
cmake --build build 
cmake --install build --prefix .   # This installs in the current directory
```

## Usage
To run the fractal generator:
```
./bin/fractal.exe
```

The `src/main.cpp` file can be editted to change the resolution, zoom, or color ranges.  

The Zooms are provided in pixel coordinates *after* the previous zoom had been applied.  
The ends of the Ranges are provided are a fraction of the maxIterations. 


## Tests
Catch2 is used for testing. Catch2 is integrated directly into the project through CMake as recommended by the Catch2 library. Separate unit tests are provided for the RGB, Zoom/ZoomList, Mandelbrot, and Fractal classes. 

After building and installing, the tests can be run with:
```
./bin/tests.exe
```


## Acknowledgment 
This project is adapted and extended from the Fractal project from the Cave of Programming Advanced C++ course by John Purcell.  
Course: https://www.caveofprogramming.com/p/learn-c-tutorial  
Code: https://github.com/caveofprogramming/advanced-cplusplus
