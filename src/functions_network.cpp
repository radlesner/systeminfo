#include "functions_network.h"

using namespace std;

void get_ip_address(int on_ip6) {
    struct ifaddrs* ifAddrStruct = NULL;
    struct ifaddrs* ifa = NULL;
    void* tmpAddrPtr = NULL;

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
            if (nr < 10)    cout << "IP Address #" << nr++ << "              : " << ifa->ifa_name << " (" << address_buffer << ")" << endl;
            else            cout << "IP Address #" << nr++ << "             : " << ifa->ifa_name << " (" << address_buffer << ")" << endl;
        }
        else if (ifa->ifa_addr->sa_family == AF_INET6 && on_ip6 == 1) {
            tmpAddrPtr =& ((struct sockaddr_in6 *) ifa->ifa_addr)->sin6_addr;
            char address_buffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, address_buffer, INET6_ADDRSTRLEN);
            if (nr < 10)    cout << "IP Address version 6 #" << nr++ << "    : " << ifa->ifa_name << " (" << address_buffer << ")" << endl;
            else            cout << "IP Address version 6 #" << nr++ << "   : " << ifa->ifa_name << " (" << address_buffer << ")" << endl;
        }
    }
    if (ifAddrStruct != NULL) freeifaddrs(ifAddrStruct);
}