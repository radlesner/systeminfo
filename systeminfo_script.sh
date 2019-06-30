#!/bin/bash

trim_quotes() {
    trim_output="${1//\"}"
    trim_output="${trim_output//\"}"
    printf "%s" "$trim_output"
}

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
if [[ -f /bedrock/etc/bedrock-release && $PATH == */bedrock/cross/* ]]; then
    case "$distro_shorthand" in
        "on" | "tiny") distro="Bedrock Linux" ;;
        *) distro="$(< /bedrock/etc/bedrock-release)"
    esac
elif [[ -f "/etc/redstar-release" ]]; then
    case "$distro_shorthand" in
        "on" | "tiny") distro="Red Star OS" ;;
        *) distro="Red Star OS $(awk -F'[^0-9*]' '$0=$2' /etc/redstar-release)"
    esac

elif [[ -f "/etc/siduction-version" ]]; then
    case "$distro_shorthand" in
        "on" | "tiny") distro="Siduction" ;;
        *) distro="Siduction ($(lsb_release -sic))"
    esac

elif type -p lsb_release >/dev/null; then
    case "$distro_shorthand" in
        "on")   lsb_flags="-sir" ;;
        "tiny") lsb_flags="-si" ;;
        *)      lsb_flags="-sd" ;;
    esac
    distro="$(lsb_release "$lsb_flags")"

elif [[ -f "/etc/GoboLinuxVersion" ]]; then
    case "$distro_shorthand" in
        "on" | "tiny") distro="GoboLinux" ;;
        *) distro="GoboLinux $(< /etc/GoboLinuxVersion)"
    esac

elif type -p guix >/dev/null; then
    case "$distro_shorthand" in
        "on" | "tiny") distro="GuixSD" ;;
        *) distro="GuixSD $(guix system -V | awk 'NR==1{printf $5}')"
    esac

elif type -p crux >/dev/null; then
    distro="$(crux)"
    case "$distro_shorthand" in
        "on")   distro="${distro//version}" ;;
        "tiny") distro="${distro//version*}" ;;
    esac

elif type -p tazpkg >/dev/null; then
    distro="SliTaz $(< /etc/slitaz-release)"

elif type -p kpt >/dev/null && \
     type -p kpm >/dev/null; then
    distro="KSLinux"

elif [[ -d "/system/app/" && -d "/system/priv-app" ]]; then
    distro="Android $(getprop ro.build.version.release)"

elif [[ -f /etc/lsb-release && "$(< /etc/lsb-release)" == *CHROMEOS* ]]; then
    distro="$(awk -F '=' '/NAME|VERSION/ {printf $2 " "}' /etc/lsb-release)"

elif [[ -f "/etc/os-release" || \
        -f "/usr/lib/os-release" || \
        -f "/etc/openwrt_release" ]]; then
    files=("/etc/os-release" "/usr/lib/os-release" "/etc/openwrt_release")

    # Source the os-release file
    for file in "${files[@]}"; do
        source "$file" && break
    done

    # Format the distro name.
    case "$distro_shorthand" in
        "on")   distro="${NAME:-${DISTRIB_ID}} ${VERSION_ID:-${DISTRIB_RELEASE}}" ;;
        "tiny") distro="${NAME:-${DISTRIB_ID:-${TAILS_PRODUCT_NAME}}}" ;;
        "off")  distro="${PRETTY_NAME:-${DISTRIB_DESCRIPTION}} ${UBUNTU_CODENAME}" ;;
    esac
else
    for release_file in /etc/*-release; do
        distro+="$(< "$release_file")"
    done

    if [[ -z "$distro" ]]; then
        case "$distro_shorthand" in
            "on" | "tiny") distro="$kernel_name" ;;
            *) distro="$kernel_name $kernel_version" ;;
        esac
        distro="${distro/DragonFly/DragonFlyBSD}"

        # Workarounds for FreeBSD based distros.
        [[ -f "/etc/pcbsd-lang" ]] && distro="PCBSD"
        [[ -f "/etc/trueos-lang" ]] && distro="TrueOS"

        # /etc/pacbsd-release is an empty file
        [[ -f "/etc/pacbsd-release" ]] && distro="PacBSD"
    fi
fi

if [[ "$(< /proc/version)" == *"Microsoft"* ||
      "$kernel_version" == *"Microsoft"* ]]; then
    case "$distro_shorthand" in
        "on")   distro+=" [Windows 10]" ;;
        "tiny") distro="Windows 10" ;;
        *)      distro+=" on Windows 10" ;;
    esac

elif [[ "$(< /proc/version)" == *"chrome-bot"* || -f "/dev/cros_ec" ]]; then
    case "$distro_shorthand" in
        "on")   distro+=" [Chrome OS]" ;;
        "tiny") distro="Chrome OS" ;;
        *)      distro+=" on Chrome OS" ;;
    esac
fi

distro="$(trim_quotes "$distro")"
distro="${distro/NAME=}"
echo $distro >> systeminfo-distro.txt

uptime -p | awk '{for (i=2; i<NF; i++) printf $i " "; print $NF}' >> systeminfo-uptime.txt
if [ -e /etc/lsb-release ] ; then
    lsb_release -r | awk {'print $2'} >> systeminfo-release.txt
    lsb_release -c | awk {'print $2'} >> systeminfo-codename.txt
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