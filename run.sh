#!/bin/bash -

mkdir build
cd ./build
cmake ..

cpu_num=`grep ^cpu\\scores /proc/cpuinfo | uniq |  awk '{print $4}'`
make -j${cpu_num}
