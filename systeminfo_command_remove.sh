#/bin/sh

	cd /systeminfo-files && rm systeminfo-uptime.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-distro.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-cpu.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-cores.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-shell.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-mem.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-swap.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-user.txt >> systeminfo-errors.txt
	cd /systeminfo-files && rm systeminfo-cpu-frequency.txt >> systeminfo-errors.txt