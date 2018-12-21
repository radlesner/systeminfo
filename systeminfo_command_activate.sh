#/bin/sh

	cd /systeminfo-files && uptime -p | cut -d p -f2 >> systeminfo-uptime.txt
	cd /systeminfo-files && lsb_release -i | cut -d\: -f2 >> systeminfo-distro.txt
	cd /systeminfo-files && cat /proc/cpuinfo | grep -i "name" --max-count=1 | cut -d\: -f2 >> systeminfo-cpu.txt
	cd /systeminfo-files && echo $SHELL >> systeminfo-shell.txt
	cd /systeminfo-files && lscpu | grep -i "CPU(s):" --max-count=1 | cut -d\: -f2 | tr -d ' '  >> systeminfo-cores.txt
	cd /systeminfo-files && cat /proc/meminfo | grep -i "MemTotal: " --max-count=1 | cut -d\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-mem.txt
	cd /systeminfo-files && cat /proc/meminfo | grep -i "MemFree: " --max-count=1 | cut -d\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-mem.txt
	cd /systeminfo-files && cat /proc/meminfo | grep -i "SwapTotal: " --max-count=1 | cut -d\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-swap.txt
	cd /systeminfo-files && cat /proc/meminfo | grep -i "SwapFree: " --max-count=1 | cut -d\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-swap.txt
	cd /systeminfo-files && echo $USER >> systeminfo-user.txt
	cd /systeminfo-files && cat /proc/cpuinfo | grep -i "cpu MHz" --max-count=1 | awk {'print $4'} >> systeminfo-cpu-frequency.txt
	cd /systeminfo-files && lscpu | grep -i "CPU max" --max-count=1 | awk {'print $4'} >> systeminfo-cpu-frequency.txt
	cd /systeminfo-files && lscpu | grep -i "CPU min" --max-count=1 | awk {'print $4'} >> systeminfo-cpu-frequency.txt