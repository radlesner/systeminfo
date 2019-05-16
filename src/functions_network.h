#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <fstream>
#include <regex>

using namespace std;

void get_ip_address(int on_ip6);
void all_network();