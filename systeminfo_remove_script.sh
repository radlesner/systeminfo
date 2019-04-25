cd /$HOME/.systeminfo-files
# SYSTEM
rm -f systeminfo-uptime.txt >> systeminfo-errors.txt
rm -f systeminfo-distro.txt >> systeminfo-errors.txt
rm -f systeminfo-arch.txt >> systeminfo-errors.txt
rm -f systeminfo-shell.txt >> systeminfo-errors.txt
rm -f systeminfo-user.txt >> systeminfo-errors.txt

# NETWORK
rm -f systeminfo-gateway-names.txt >> systeminfo-errors.txt
rm -f systeminfo-gateway-ip.txt >> systeminfo-errors.txt

# MEMOWY
rm -f systeminfo-mem.txt >> systeminfo-errors.txt
rm -f systeminfo-swap.txt >> systeminfo-errors.txt

# CPU
rm -f systeminfo-cpu-status.txt >> systeminfo-errors.txt
rm -f systeminfo-cpu-frequency_max.txt >> systeminfo-errors.txt
rm -f systeminfo-cpu-frequency_min.txt >> systeminfo-errors.txt
rm -f systeminfo-cpu.txt >> systeminfo-errors.txt
rm -f systeminfo-cores.txt >> systeminfo-errors.txt
rm -f systeminfo-cpu-frequency*.txt >> systeminfo-errors.txt