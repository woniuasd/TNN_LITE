#!/bin/bash

SHARED_LIB="ON"
OPENMP="ON"
OPENCL="OFF"
QUANTIZATION="OFF"
CC=gcc
CXX=g++

rm -rf build
mkdir build
cd build

cmake .. \
    -DCMAKE_SYSTEM_NAME=Linux  \
    -DTNN_TEST_ENABLE=ON \
    -DTNN_CPU_ENABLE=ON \
    -DCMAKE_C_COMPILER=$CC \
    -DCMAKE_CXX_COMPILER=$CXX \
    -DTNN_X86_ENABLE:BOOL=ON \
    -DTNN_OPENMP_ENABLE:BOOL=$OPENMP \
    -DTNN_OPENCL_ENABLE:BOOL=$OPENCL \
    -DTNN_QUANTIZATION_ENABLE:BOOL=$QUANTIZATION \
    -DTNN_BENCHMARK_MODE=ON \
    -DTNN_BUILD_SHARED:BOOL=$SHARED_LIB 

make -j7

# check compile error, or ci will not stop
# if [ 0 -ne $? ]
# then
#     exit -1
# fi
