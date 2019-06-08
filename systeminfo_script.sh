cd /$HOME/.systeminfo-files

# CPU
if [ -e /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq ] ; then
   cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_cur_freq >> systeminfo-cpu-status.txt
fi

if [ -e /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq ] ; then
    cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq >> systeminfo-cpu-frequency_max.txt
fi

if [ -e /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq ] ; then
    cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq >> systeminfo-cpu-frequency_min.txt
fi
cat /proc/cpuinfo | grep -i "model name" --max-count=1 | awk '{for (i=4; i<NF; i++) printf $i " "; print $NF}' >> systeminfo-cpu.txt

cat /proc/cpuinfo | grep "processor" | awk {'print $3'} >> systeminfo-cores.txt

#lscpu | grep -i "CPU(s):" --max-count=1 | awk {'print $2'}  >> systeminfo-cores.txt
#cat /proc/cpuinfo | grep -i "cpu cores" --max-count=1 | awk {'print $4'}  >> systeminfo-cores.txt

# NETWORK
# ip r | grep default | awk '/enp/ {print $5}''/wlp/ {print $5}''/eth/ {print $5}''/wlan/ {print $5}''/bond/ {print $5}' >> systeminfo-gateway-names.txt
# ip r | grep default | awk '/enp/ {print $3}''/wlp/ {print $3}''/eth/ {print $3}''/wlan/ {print $3}''/bond/ {print $3}' >> systeminfo-gateway-ip.txt

route -n | grep 'UG[ \t]' | awk '{print $2}' >> systeminfo-gateway-ip.txt
route -n | grep 'UG[ \t]' | awk '{print $8}' >> systeminfo-gateway-names.txt
route -n | grep 'UG[ \t]' | awk '{print $8 " " $2}' >> systeminfo-gateway.txt

# SYSTEM
uptime -p | awk '{for (i=2; i<NF; i++) printf $i " "; print $NF}' >> systeminfo-uptime.txt
lsb_release -i | awk {'print $3'} >> systeminfo-distro.txt
lsb_release -r | awk {'print $2'} >> systeminfo-distro.txt
lsb_release -c | awk {'print $2'} >> systeminfo-distro.txt
uname -m >> systeminfo-arch.txt
getconf LONG_BIT >> systeminfo-arch.txt
echo $USER >> systeminfo-user.txt
echo $SHELL >> systeminfo-shell.txt

# MEMORY
cat /proc/meminfo | grep -i "MemTotal: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-mem.txt
cat /proc/meminfo | grep -i "MemFree: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-mem.txt
cat /proc/meminfo | grep -i "MemAvailable:" --max-count=1 | awk {'print $2'} >> systeminfo-mem.txt
cat /proc/meminfo | grep -i "SwapTotal: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-swap.txt
cat /proc/meminfo | grep -i "SwapFree: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-swap.txt