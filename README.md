# LAFG
Linear algebra library for graphics.

## Requirements
C++20 compatable compiler.

## Installation
Use CMake to install system-wide:
```sh
mkdir build
cd build
cmake ..
sudo cmake --install .
```

## Using
Add `find_package(LAFG REQUIRED)` in your CMakeLists.txt and link with your
project.
Or put include folder into your project folder to use loacally.

## Matrix layout
Column layout is default. Use `#define LAFG_USE_ROW_LAYOUT` before including
LAFG headers for row layout.

## Double precision
Some functions have single and double-precision versions. Single precision
version is suffixed with 'f'. For example `normalize` and `normalizef`.
