# systeminfo
A simple program showing system information in C++ language
# Usage
```
./systeminfo
```
# Compile
```
$ ./build.sh
```
or
```
$ make clean
$ make
```
or
```
$ g++ src/*.cpp -o systeminfo
```
# Examples of the program results
systeminfo
```
OS Name:			Linux
Distribution:			Fedora
Kernel version:			4.13.9-300.fc27.x86_64
System architecture:		x86_64
CPU:				Intel(R) Core(TM) i5-2520M CPU @ 2.50GHz
Cores:		  		4 cores
RAM Total/Free:			7.86/1.92 GB
Swap Total/Free:		7.99/7.99 GB
Shell:				Z-Shell (/bin/zsh)
Logged user:			krupier
Hostname:			pancernik
Uptime:			        4 hours, 50 minutes
```
systeminfo --help
```
Usage: system [optional_option]
Options:
	-m	--memory		RAM and Swap information gigabyte form
	-M	--memory-megabyte	RAM and Swap information megabyte form
	-s	--system		System and hardware information
	-h	--ssh			SSH information
	-c	--cpu			CPU information
	-l	--logo			Show the logo
		--check-files		Check integration files
		--help			Help panel
		--version		Version program and compilation
					information
```
