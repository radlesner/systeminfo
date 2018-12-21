#/bin/sh

chmod +x systeminfo_command_activate.sh
chmod +x systeminfo_command_remove.sh

sudo cp Debug/systeminfo				/usr/bin
sudo cp systeminfo_command_activate.sh	/usr/bin
sudo cp systeminfo_command_remove.sh	/usr/bin