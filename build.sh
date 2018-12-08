#bin/sh
printf "Files:\n"
ls -1 src/*.cpp
printf "Command: g++ src/*.cpp -o Debug/systeminfo\n"
g++ src/*.cpp -o Debug/systeminfo
