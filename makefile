all: systeminfo

systeminfo:
	@g++ src/*.cpp -Wall -Wextra -pedantic -o systeminfo

install:
	@cp systeminfo /usr/bin/
	@cp systeminfo_script.sh /usr/bin/

clean:
	@rm systeminfo
