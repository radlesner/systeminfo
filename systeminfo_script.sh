#!/bin/sh

cd $HOME/.systeminfo-files/

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

if [ -e /sys/class/hwmon/hwmon*/fan1_input ] ; then
    cat /sys/class/hwmon/hwmon*/fan1_input >> systeminfo-cpu-fan-speed.txt
fi

if [ -e /sys/class/hwmon/ ] ; then
    ls -l /sys/class/hwmon/ | grep -c "hwmon" >> systeminfo-hwmon-exist.txt
fi

awk -F ': | @' '/model name|Processor|^cpu model|chip type|^cpu type/ {printf $2; printf "\n"; exit}' /proc/cpuinfo >> systeminfo-cpu.txt
cat /proc/cpuinfo | grep -c "^processor" >> systeminfo-theards.txt
awk '/^core id/&&!a[$0]++{++i} END {print i}' /proc/cpuinfo >> systeminfo-cores.txt

# HARDWARE
if [ -e /sys/devices/virtual/dmi/id/product_version ] ; then
    model="$(cat /sys/devices/virtual/dmi/id/product_name)"
    model+=" $(cat /sys/devices/virtual/dmi/id/product_version)"
    echo $model >> systeminfo-model.txt
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
    lsb_release -r | awk {'print $2'} >> systeminfo-release.txt
    lsb_release -c | awk {'print $2'} >> systeminfo-codename.txt
else
    cat /etc/os-release | grep "^NAME" | sort -n | tr -d '"' | awk -F '=' '{print $2}' >> systeminfo-distro.txt
fi

if [ -e /etc/os-release ] ; then
    awk -F '=' -F '"' '/COLOR/ {printf $2 "\n"}' /etc/os-release >> systeminfo-color.txt
fi

uname -m >> systeminfo-arch.txt
getconf LONG_BIT >> systeminfo-arch.txt
echo $USER >> systeminfo-user.txt
echo $SHELL >> systeminfo-shell.txt
stty size | awk '{printf $1"\n"$2"\n"}' >> systeminfo-ter-size.txt

# MEMORY
if [ -e /proc/meminfo ] ; then
    cat /proc/meminfo | grep -i "MemTotal: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-mem.txt
    cat /proc/meminfo | grep -i "MemFree: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-mem.txt
    cat /proc/meminfo | grep -i "MemAvailable:" --max-count=1 | awk {'print $2'} >> systeminfo-mem.txt
    cat /proc/meminfo | grep -i "SwapTotal: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-swap.txt
    cat /proc/meminfo | grep -i "SwapFree: " --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-swap.txt
fi

#DISKS
df -m | grep -i "/dev/sd" | sort -n | awk '{print $1}' >> systeminfo-disks-name.txt
df -m | grep -i "/dev/hd" | sort -n | awk '{print $1}' >> systeminfo-disks-name.txt
df -m | grep -i "/dev/fd" | sort -n | awk '{print $1}' >> systeminfo-disks-name.txt
df -m | grep -i "/dev/mmcblk" | awk '{print $1}' >> systeminfo-disks-name.txt
df -m | grep -i "/dev/ro" | awk '{print $1}' >> systeminfo-disks-name.txt

df -m | grep -i "/dev/sd" | sort -n | awk '{print $2}' >> systeminfo-disks-size.txt
df -m | grep -i "/dev/hd" | sort -n | awk '{print $2}' >> systeminfo-disks-size.txt
df -m | grep -i "/dev/fd" | sort -n | awk '{print $2}' >> systeminfo-disks-size.txt
df -m | grep -i "/dev/mmcblk" | awk '{print $2}' >> systeminfo-disks-size.txt
df -m | grep -i "/dev/ro" | awk '{print $2}' >> systeminfo-disks-size.txt

df -m | grep -i "/dev/sd" | sort -n | awk '{print $3}' >> systeminfo-disks-used.txt
df -m | grep -i "/dev/hd" | sort -n | awk '{print $3}' >> systeminfo-disks-used.txt
df -m | grep -i "/dev/fd" | sort -n | awk '{print $3}' >> systeminfo-disks-used.txt
df -m | grep -i "/dev/mmcblk" | awk '{print $3}' >> systeminfo-disks-used.txt
df -m | grep -i "/dev/ro" | awk '{print $3}' >> systeminfo-disks-name.txt

df -m | grep -i "/dev/sd" | sort -n | awk '{print $4}' >> systeminfo-disks-avail.txt
df -m | grep -i "/dev/hd" | sort -n | awk '{print $4}' >> systeminfo-disks-avail.txt
df -m | grep -i "/dev/fd" | sort -n | awk '{print $4}' >> systeminfo-disks-avail.txt
df -m | grep -i "/dev/mmcblk" | awk '{print $4}' >> systeminfo-disks-avail.txt
df -m | grep -i "/dev/ro" | awk '{print $4}' >> systeminfo-disks-name.txt

df -m | grep -i "/dev/sd" | sort -n | awk '{print $5}' >> systeminfo-disks-procent-usage.txt
df -m | grep -i "/dev/hd" | sort -n | awk '{print $5}' >> systeminfo-disks-procent-usage.txt
df -m | grep -i "/dev/fd" | sort -n | awk '{print $5}' >> systeminfo-disks-procent-usage.txt
df -m | grep -i "/dev/mmcblk" | awk '{print $5}' >> systeminfo-disks-procent-usage.txt
df -m | grep -i "/dev/ro" | awk '{print $5}' >> systeminfo-disks-name.txt

df -m | grep -i "/dev/sd" | sort -n | awk '{print $6}' >> systeminfo-disks-mount.txt
df -m | grep -i "/dev/hd" | sort -n | awk '{print $6}' >> systeminfo-disks-mount.txt
df -m | grep -i "/dev/fd" | sort -n | awk '{print $6}' >> systeminfo-disks-mount.txt
df -m | grep -i "/dev/mmcblk" | awk '{print $6}' >> systeminfo-disks-mount.txt
df -m | grep -i "/dev/ro" | awk '{print $6}' >> systeminfo-disks-name.txt

# NETWORK
if [ -e /proc/net/route ] ; then
    cat /proc/net/route  | grep '0003' | awk '{print $1 "\n" $3}' >> systeminfo-gateway.txt
fi