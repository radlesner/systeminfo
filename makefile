all: systeminfo

systeminfo:
	@g++ src/*.cpp -o systeminfo

install:
	@cp systeminfo /usr/bin/
	@cp systeminfo_script.sh /usr/bin/
	@cp systeminfo_remove_script.sh /usr/bin/

clean:
	@rm systeminfo