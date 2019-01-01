all: systeminfo

systeminfo:
	@g++ src/*.cpp -o systeminfo

install:
	@cp systeminfo /usr/bin/

clean:
	@rm systeminfo