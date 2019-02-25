all: systeminfo

systeminfo:
	@g++ src/*.cpp -o systeminfo

install:
	@cp systeminfo /usr/bin/
	@cp systeminfo_script.sh /systeminfo-files/scripts
	@cp systeminfo_remove_script.sh /systeminfo-files/scripts

clean:
	@rm systeminfo