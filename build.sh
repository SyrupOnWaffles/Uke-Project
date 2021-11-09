#!/usr/bin/env bash
mkdir build;cd build
#? CMake stuff 
cmake ../
make
#? Remove Unnecesary files
rm CMakeFiles/ -r; rm Testing/ -r; rm cmake_install.cmake; rm CMakeCache.txt; rm CTestTestfile.cmake; rm DartConfiguration.tcl; rm main.cpp; rm Makefile
#? Run
./ukulele