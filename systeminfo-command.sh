#/bin/sh

if [ "-a" == $1 ]; then
	cd /systeminfo-files && uptime -p | cut -d p -f2 >> systeminfo-uptime.txt
	cd /systeminfo-files && lsb_release -i | awk {'print $3'} >> systeminfo-distro.txt
	cd /systeminfo-files && lsb_release -r | awk {'print $2'} >> systeminfo-distro.txt
	cd /systeminfo-files && echo $USER >> systeminfo-user.txt
	cd /systeminfo-files && echo $SHELL >> systeminfo-shell.txt

	cd /systeminfo-files && cat /proc/meminfo | grep -i "MemTotal: " --max-count=1 | cut -d\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-mem.txt
	cd /systeminfo-files && cat /proc/meminfo | grep -i "MemFree: " --max-count=1 | cut -d\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-mem.txt
	cd /systeminfo-files && cat /proc/meminfo | grep -i "MemAvailable:" --max-count=1 | awk {'print $2'} >> systeminfo-mem.txt
	cd /systeminfo-files && cat /proc/meminfo | grep -i "SwapTotal: " --max-count=1 | cut -d\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-swap.txt
	cd /systeminfo-files && cat /proc/meminfo | grep -i "SwapFree: " --max-count=1 | cut -d\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-swap.txt

	cd /systeminfo-files && lscpu | grep "Model name:" --max-count=1 | awk '{for (i=3; i<NF; i++) printf $i " "; print $NF}' >> systeminfo-cpu.txt
	cd /systeminfo-files && lscpu | grep -i "CPU(s):" --max-count=1 | cut -d\: -f2 | tr -d ' '  >> systeminfo-cores.txt
	cd /systeminfo-files && lscpu | grep -i "max" --max-count=1 | awk {'print $4'} >> systeminfo-cpu-frequency_max.txt
	cd /systeminfo-files && lscpu | grep -i "min" --max-count=1 | awk {'print $4'} >> systeminfo-cpu-frequency_min.txt
elif [ "-d" == $1 ]; then
	cd /systeminfo-files && rm systeminfo-uptime.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-distro.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-shell.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-user.txt >> systeminfo-errors.txt

	cd /systeminfo-files && rm systeminfo-mem.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-swap.txt >> systeminfo-errors.txt

	cd /systeminfo-files && rm systeminfo-cpu.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-cores.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-cpu-frequency*.txt >> systeminfo-errors.txt
fi
