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

# NETWORK
if [ -e /usr/bin/route ] ; then
    route -n | grep 'UG[ \t]' | awk '{print $2}' >> systeminfo-gateway-ip.txt
    route -n | grep 'UG[ \t]' | awk '{print $8}' >> systeminfo-gateway-names.txt
    route -n | grep 'UG[ \t]' | awk '{print $8 " " $2}' >> systeminfo-gateway.txt
fi

# HARDWARE
if [ -e /sys/devices/virtual/dmi/id/product_family ] ; then
    cat /sys/devices/virtual/dmi/id/product_family >> systeminfo-model.txt
fi
if [ -e /sys/devices/virtual/dmi/id/board_name ] ; then
    cat /sys/devices/virtual/dmi/id/board_name >> systeminfo-motherboard.txt
fi
if [ -e /sys/devices/virtual/dmi/id/board_vendor ] ; then
    cat /sys/devices/virtual/dmi/id/board_vendor >> systeminfo-motherboard-manufact.txt
fi
if [ -e /sys/devices/virtual/dmi/id/bios_vendor ] ; then
    cat /sys/devices/virtual/dmi/id/bios_vendor >> systeminfo-bios-manufact.txt
fi
if [ -e /sys/devices/virtual/dmi/id/bios_version ] ; then
    cat /sys/devices/virtual/dmi/id/bios_version >> systeminfo-bios-version.txt
fi
if [ -e /sys/devices/virtual/dmi/id/bios_date ] ; then
    cat /sys/devices/virtual/dmi/id/bios_date >> systeminfo-bios-date.txt
fi

# SYSTEM
uptime -p | awk '{for (i=2; i<NF; i++) printf $i " "; print $NF}' >> systeminfo-uptime.txt
if [ -e /etc/lsb-release ] ; then
    lsb_release -i | awk {'print $3'} >> systeminfo-distro.txt
    lsb_release -r | awk {'print $2'} >> systeminfo-distro.txt
    lsb_release -c | awk {'print $2'} >> systeminfo-distro.txt
else
    cat /etc/os-release | grep PRETTY_NAME | tr -d '"' | cut -c 13-56 >> systeminfo-distro.txt
fi
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

#DISKS
df -m | grep -i "/dev/sd" | sort -n | awk '{print $1}' >> systeminfo-disks-name.txt
df -m | grep -i "/dev/hd" | sort -n | awk '{print $1}' >> systeminfo-disks-name.txt
df -m | grep -i "/dev/fd" | sort -n | awk '{print $1}' >> systeminfo-disks-name.txt
df -m | grep -i "/dev/mmcblk" | sort -n | awk '{print $1}' >> systeminfo-disks-name.txt
df -m | grep -i "/dev/ro" | sort -n | awk '{print $1}' >> systeminfo-disks-name.txt

df -m | grep -i "/dev/sd" | sort -n | awk '{print $3}' >> systeminfo-disks-used.txt
df -m | grep -i "/dev/hd" | sort -n | awk '{print $3}' >> systeminfo-disks-used.txt
df -m | grep -i "/dev/fd" | sort -n | awk '{print $3}' >> systeminfo-disks-used.txt
df -m | grep -i "/dev/mmcblk" | sort -n | awk '{print $3}' >> systeminfo-disks-used.txt
df -m | grep -i "/dev/ro" | sort -n | awk '{print $3}' >> systeminfo-disks-name.txt

df -m | grep -i "/dev/sd" | sort -n | awk '{print $4}' >> systeminfo-disks-avail.txt
df -m | grep -i "/dev/hd" | sort -n | awk '{print $4}' >> systeminfo-disks-avail.txt
df -m | grep -i "/dev/fd" | sort -n | awk '{print $4}' >> systeminfo-disks-avail.txt
df -m | grep -i "/dev/mmcblk" | sort -n | awk '{print $4}' >> systeminfo-disks-avail.txt
df -m | grep -i "/dev/ro" | sort -n | awk '{print $4}' >> systeminfo-disks-name.txt

df -m | grep -i "/dev/sd" | sort -n | awk '{print $5}' >> systeminfo-disks-procent-usage.txt
df -m | grep -i "/dev/hd" | sort -n | awk '{print $5}' >> systeminfo-disks-procent-usage.txt
df -m | grep -i "/dev/fd" | sort -n | awk '{print $5}' >> systeminfo-disks-procent-usage.txt
df -m | grep -i "/dev/mmcblk" | sort -n | awk '{print $5}' >> systeminfo-disks-procent-usage.txt
df -m | grep -i "/dev/ro" | sort -n | awk '{print $5}' >> systeminfo-disks-name.txt

df -m | grep -i "/dev/sd" | sort -n | awk '{print $6}' >> systeminfo-disks-mount.txt
df -m | grep -i "/dev/hd" | sort -n | awk '{print $6}' >> systeminfo-disks-mount.txt
df -m | grep -i "/dev/fd" | sort -n | awk '{print $6}' >> systeminfo-disks-mount.txt
df -m | grep -i "/dev/mmcblk" | sort -n | awk '{print $6}' >> systeminfo-disks-mount.txt
df -m | grep -i "/dev/ro" | sort -n | awk '{print $6}' >> systeminfo-disks-name.txt
