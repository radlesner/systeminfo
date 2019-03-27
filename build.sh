#!/bin/sh
printf "Files:\n"
ls -1 src/*.cpp

printf "Command:\n"
if [ -e systeminfo ] ; then
    printf "@ make clean\n"
    make clean
fi
printf "@ make\n"
make

#g++ src/*.cpp -o Debug/systeminfo
