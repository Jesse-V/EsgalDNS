#!/bin/sh

# make the code-style consistent
for f in $(find src/ -type f -name "*.c*" | grep -v "libs"); do
   clang-format-3.6 -style="{BasedOnStyle: chromium, BreakBeforeBraces: Allman, MaxEmptyLinesToKeep: 3}" -i $f
done
# AlignConsecutiveAssignments: true
for f in $(find src/ -type f -name "*.h*" | grep -v "libs"); do
   clang-format-3.6 -style="{BasedOnStyle: chromium, BreakBeforeBraces: Allman, MaxEmptyLinesToKeep: 3}" -i $f
done

# prepare environment
mkdir -p build/
cd build
cmake ../src # -DCMAKE_BUILD_TYPE=Debug

# build
cpus=$(grep -c ^processor /proc/cpuinfo)
make -j $cpus
cp tor-onions* ../
