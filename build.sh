#bin/sh
printf "Files:\n"
ls -1 src/*.cpp

printf "Command:\n"
printf "@ make clean\n"
make clean
printf "@ make\n"
make

#g++ src/*.cpp -o Debug/systeminfo
