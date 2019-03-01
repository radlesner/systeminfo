cd /systeminfo-files
cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_cur_freq >> systeminfo-cpu-status.txt
lscpu | grep -i "max" --max-count=1 | awk {'print $4'} >> systeminfo-cpu-frequency_max.txt
lscpu | grep -i "min" --max-count=1 | awk {'print $4'} >> systeminfo-cpu-frequency_min.txt
cat /proc/cpuinfo | grep -i "model name" --max-count=1 | awk '{for (i=4; i<NF; i++) printf $i " "; print $NF}' >> systeminfo-cpu.txt
lscpu | grep -i "CPU(s):" --max-count=1 | awk {'print $2'}  >> systeminfo-cores.txt
cat /proc/cpuinfo | grep -i "cpu cores" --max-count=1 | awk {'print $4'}  >> systeminfo-cores.txt

uptime -p | awk '{for (i=2; i<NF; i++) printf $i " "; print $NF}' >> systeminfo-uptime.txt
lsb_release -i | awk {'print $3'} >> systeminfo-distro.txt
lsb_release -r | awk {'print $2'} >> systeminfo-distro.txt
lsb_release -c | awk {'print $2'} >> systeminfo-distro.txt
arch >> systeminfo-arch.txt
getconf LONG_BIT >> systeminfo-arch.txt
echo $USER >> systeminfo-user.txt
echo $SHELL >> systeminfo-shell.txt

cat /proc/meminfo | grep -i "MemTotal: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-mem.txt
cat /proc/meminfo | grep -i "MemFree: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-mem.txt
cat /proc/meminfo | grep -i "MemAvailable:" --max-count=1 | awk {'print $2'} >> systeminfo-mem.txt
cat /proc/meminfo | grep -i "SwapTotal: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-swap.txt
cat /proc/meminfo | grep -i "SwapFree: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-swap.txt