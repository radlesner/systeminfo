#include <iostream>
#include <string>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <fstream>

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>

using namespace std;

void get_ip_address(int on_ip6);
int get_ip_gateway(in_addr_t* addr, char *interface);