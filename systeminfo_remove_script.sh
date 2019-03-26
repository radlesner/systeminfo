cd /$HOME/.systeminfo-files
# SYSTEM
rm systeminfo-uptime.txt >> systeminfo-errors.txt
rm systeminfo-distro.txt >> systeminfo-errors.txt
rm systeminfo-arch.txt >> systeminfo-errors.txt
rm systeminfo-shell.txt >> systeminfo-errors.txt
rm systeminfo-user.txt >> systeminfo-errors.txt

# NETWORK
rm systeminfo-gateway-names.txt >> systeminfo-errors.txt
rm systeminfo-gateway-ip.txt >> systeminfo-errors.txt

# MEMOWY
rm systeminfo-mem.txt >> systeminfo-errors.txt
rm systeminfo-swap.txt >> systeminfo-errors.txt

# CPU
if [ -e /home/$USER/.systeminfo-files/systeminfo-cpu-status.txt ] ; then
    rm systeminfo-cpu-status.txt >> systeminfo-errors.txt
fi
rm systeminfo-cpu.txt >> systeminfo-errors.txt
rm systeminfo-cores.txt >> systeminfo-errors.txt
rm systeminfo-cpu-frequency*.txt >> systeminfo-errors.txt