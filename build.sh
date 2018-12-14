#bin/sh
printf "Files:\n"
ls -1 src/*.cpp
printf "Command: make clean & make\n"
cd Debug && make clean && make

#g++ src/*.cpp -o Debug/systeminfo
