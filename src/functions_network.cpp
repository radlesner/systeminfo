#include "functions_network.h"

using namespace std;

void get_ip_address(int on_ip6) {
    struct ifaddrs* ifAddrStruct = NULL;
    struct ifaddrs* ifa = NULL;
    void* tmpAddrPtr = NULL;

    string text_output;
    int nr = 1;

    getifaddrs(&ifAddrStruct);

    for(ifa = ifAddrStruct;  ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET) {
            tmpAddrPtr =& ((struct sockaddr_in *) ifa->ifa_addr)->sin_addr;
            char address_buffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, address_buffer, INET_ADDRSTRLEN);

            int count = 0;
            text_output = "IP address (" + (string)ifa->ifa_name + ")";
            count = 26 - text_output.length();
            for(int i = 0; i < count; i++) {
                text_output = text_output + " ";
            }

            cout << text_output << ": " << address_buffer <<  endl;
        }
        else if (ifa->ifa_addr->sa_family == AF_INET6 && on_ip6 == 1) {
            tmpAddrPtr =& ((struct sockaddr_in6 *) ifa->ifa_addr)->sin6_addr;
            char address_buffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, address_buffer, INET6_ADDRSTRLEN);
            if (nr < 10)    cout << "IP address version 6 #" << nr++ << "   : " << ifa->ifa_name << " (" << address_buffer << ")" << endl;
            else            cout << "IP address version 6 #" << nr++ << "  : " << ifa->ifa_name << " (" << address_buffer << ")" << endl;
        }
    }
    if (ifAddrStruct != NULL) freeifaddrs(ifAddrStruct);
}

int get_ip_gateway(in_addr_t* addr, char *interface) {
    long destination, gateway;
    char iface[IF_NAMESIZE];
    char buf[4096];

    memset(iface, 0, sizeof(iface));
    memset(buf, 0, sizeof(buf));

    FILE * file;
    file = fopen("/proc/net/route", "r");
    if (!file) return -1;

    while(fgets(buf, sizeof(buf), file)) {
        if (sscanf(buf, "%s %lx %lx", iface, &destination, &gateway) == 3) {
            if (destination == 0) {
                *addr = gateway;
                strcpy(interface, iface);
                fclose(file);
                return 0;
            }
        }
    }
    if (file) fclose(file);
    return -1;
}