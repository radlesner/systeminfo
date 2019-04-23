#include "functions_network.h"
#include "functions_file_operations.h"
#include "functions_output.h"
#include "functions_file.h"

using namespace std;

void get_ip_address(int on_ip6) {
    struct ifaddrs* ifAddrStruct = NULL;
    struct ifaddrs* ifa = NULL;
    void* tmpAddrPtr = NULL;

    string text_output;
    int nr = 1;

    getifaddrs(&ifAddrStruct);

    for(ifa = ifAddrStruct;  ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) continue;
        if (ifa->ifa_addr->sa_family == AF_INET) {
            tmpAddrPtr =& ((struct sockaddr_in *) ifa->ifa_addr)->sin_addr;
            char address_buffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, address_buffer, INET_ADDRSTRLEN);

                int count = 0;
                text_output = "IPv4    (" + static_cast<string>(ifa->ifa_name) + ")";
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
                int count = 0;
                text_output = "IPv6    (" + (string)ifa->ifa_name + ")";
                count = 26 - text_output.length();
                for(int i = 0; i < count; i++) {
                    text_output = text_output + " ";
                }
                cout << text_output << ": " << address_buffer <<  endl;
        }
    }
    if (text_output.length() > 1) separator("");
    if (ifAddrStruct != NULL) freeifaddrs(ifAddrStruct);
}

void all_network() {
    /*
        GATEWAY
    */
    ifstream file;
    int nr = 0, i = 0;
    string interfaces[32];
    string addresses[32];
    string text;
    string final_output;
    file.open(home_path()+"/.systeminfo-files/systeminfo-gateway-names.txt");
    if (file.good() == true) {
        while(!file.eof()) {
            getline(file, text);
            nr++;
        }
    }
    file.close();
    /*
        GATEWAY END
        ADDRESS AND NETMASK
    */
    struct ifaddrs* ifAddrStruct = NULL;
    struct ifaddrs* ifa = NULL;
    void* tmpAddrPtr = NULL;
    unsigned int tmpMask;

    string netmask_output, address_output;

    getifaddrs(&ifAddrStruct);
    /*
        ADDRESS AND NETMASK END
        ADDRESS AND NETMASK OUTPUT
    */
    for(ifa = ifAddrStruct;  ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) continue;
        if (ifa->ifa_addr->sa_family == AF_INET) {
            char address_buffer[INET_ADDRSTRLEN];
            char mask_buffer[INET_ADDRSTRLEN];

            tmpAddrPtr = &((struct sockaddr_in *)(ifa->ifa_addr))->sin_addr;
            inet_ntop(AF_INET, tmpAddrPtr, address_buffer, INET_ADDRSTRLEN);

            tmpAddrPtr = &((struct sockaddr_in *)(ifa->ifa_netmask))->sin_addr;
            inet_ntop(AF_INET, tmpAddrPtr, mask_buffer, INET_ADDRSTRLEN);

            tmpMask = ((struct sockaddr_in *)(ifa->ifa_netmask))->sin_addr.s_addr;

            address_output = "IPv4    (" + static_cast<string>(ifa->ifa_name) + ")";
            netmask_output = "Netmask (" + static_cast<string>(ifa->ifa_name) + ")";
            int count = 0;
            count = 26 - netmask_output.length();
            for(int i = 0; i < count; i++) {
                address_output = address_output + " ";
                netmask_output = netmask_output + " ";
            }
            cout << address_output << ": " << address_buffer << endl;
            cout << netmask_output << ": " << mask_buffer <<  endl;
            /*
                ADDRESS AND NETMASK OUTPUT END
                GATEWAY OUTPUT
            */
            if (static_cast<string>(ifa->ifa_name) == "lo") {
                if (address_output.length() > 1) separator("");
                continue;
            }
            else {
                i++;
                interfaces[i] = open_file(home_path()+"/.systeminfo-files/systeminfo-gateway-names.txt", i);
                addresses[i] = open_file(home_path()+"/.systeminfo-files/systeminfo-gateway-ip.txt", i);

                final_output = "Gateway (" + interfaces[i] + ")";
                count = 26 - final_output.length();
                for(int  x = 0; x < count; x++) {
                    final_output = final_output + " ";
                }
                if (interfaces[i] != "N/A") cout << final_output << ": " << addresses[i] << endl;
                /*
                    GATEWAY OUTPUT END
                */
                if (address_output.length() > 1) separator("");
            }
        }
    }
    if (ifAddrStruct != NULL) freeifaddrs(ifAddrStruct);
}