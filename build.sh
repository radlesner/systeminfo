#!/bin/sh
printf "Files:\n"
ls -1 src/*.cpp
wc -l src/*.cpp | grep -i "total" | awk '{printf $1}'
printf " lines\n\n"

printf "Command:\n"
if [ -e systeminfo ] ; then
    printf "$ make clean\n"
    make clean
fi
printf "$ make\n"
make

#g++ src/*.cpp -o Debug/systeminfo