#!/bin/bash

mkdir -p cmake-build-mingw
cd cmake-build-mingw
x86_64-w64-mingw32-cmake ..
make