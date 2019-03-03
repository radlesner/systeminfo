#include "functions_network.h"
#include "functions_file_operations.h"

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

void get_ip_gateway() {
    ifstream file;
    int nr = 0;
    string interfaces[32];
    string addresses[32];
    string text, final_output[32];

    file.open("/systeminfo-files/systeminfo-gateway-names.txt");
    if (file.good() == true) {
        while(!file.eof()) {
            getline(file, text);
            nr++;
        }
    }
    file.close();

    for(int i = 1; i < nr; i++) {
        interfaces[i] = open_file("/systeminfo-files/systeminfo-gateway-names.txt", i);
        addresses[i] = open_file("/systeminfo-files/systeminfo-gateway-ip.txt", i);

        final_output[i] = "IP gateway (" + interfaces[i] + ")";
        int count = 0;
        count = 26 - final_output[i].length();
        for(int  x = 0; x < count; x++) {
            final_output[i] = final_output[i] + " ";
        }
        cout << final_output[i] << ": " << addresses[i] << endl;
    }
}