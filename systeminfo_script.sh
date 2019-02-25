cd /systeminfo-files && cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_cur_freq >> systeminfo-cpu-status.txt
cd /systeminfo-files && lscpu | grep -i "max" --max-count=1 | awk {'print $4'} >> systeminfo-cpu-frequency_max.txt
cd /systeminfo-files && lscpu | grep -i "min" --max-count=1 | awk {'print $4'} >> systeminfo-cpu-frequency_min.txt
cd /systeminfo-files && cat /proc/cpuinfo | grep -i "model name" --max-count=1 | awk '{for (i=4; i<NF; i++) printf $i " "; print $NF}' >> systeminfo-cpu.txt
cd /systeminfo-files && lscpu | grep -i "CPU(s):" --max-count=1 | awk {'print $2'}  >> systeminfo-cores.txt

cd /systeminfo-files && uptime -p | awk '{for (i=2; i<NF; i++) printf $i " "; print $NF}' >> systeminfo-uptime.txt
cd /systeminfo-files && lsb_release -i | awk {'print $3'} >> systeminfo-distro.txt
cd /systeminfo-files && lsb_release -r | awk {'print $2'} >> systeminfo-distro.txt
cd /systeminfo-files && arch >> systeminfo-distro.txt
cd /systeminfo-files && getconf LONG_BIT >> systeminfo-distro.txt
cd /systeminfo-files && echo $USER >> systeminfo-user.txt
cd /systeminfo-files && echo $SHELL >> systeminfo-shell.txt

cd /systeminfo-files && cat /proc/meminfo | grep -i "MemTotal: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-mem.txt
cd /systeminfo-files && cat /proc/meminfo | grep -i "MemFree: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-mem.txt
cd /systeminfo-files && cat /proc/meminfo | grep -i "MemAvailable:" --max-count=1 | awk {'print $2'} >> systeminfo-mem.txt
cd /systeminfo-files && cat /proc/meminfo | grep -i "SwapTotal: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-swap.txt
cd /systeminfo-files && cat /proc/meminfo | grep -i "SwapFree: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-swap.txt