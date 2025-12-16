#!/bin/bash
set -e

mkdir -p build install
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B build -S ./src
cmake --build build --target $1
cmake --install build/ --prefix install/