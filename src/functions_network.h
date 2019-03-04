#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <fstream>

using namespace std;

void get_ip_address(int on_ip6);
void get_ip_gateway();
unsigned int cidrMask(unsigned int n);
void get_netmask();

void all_network();