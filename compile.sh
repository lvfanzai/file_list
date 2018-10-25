#!/bin/bash
rm -rf CMakeFiles
rm -rf cmake_install.cmake
rm -rf Makefile
cmake .
make
./main_process