#include "functions_network.h"
#include "functions_file_operations.h"
#include "functions_output.h"
#include "functions_file.h"
#include "functions_strings_operations.h"

using namespace std;

void get_ip_address(int on_ip6)
{
    struct ifaddrs* ifAddrStruct = NULL;
    struct ifaddrs* ifa = NULL;
    void* tmpAddrPtr = NULL;

    string text_output;
    int nr = 1;

    getifaddrs(&ifAddrStruct);

    for(ifa = ifAddrStruct;  ifa != NULL; ifa = ifa->ifa_next)
    {
        if (!ifa->ifa_addr) continue;
        if (ifa->ifa_addr->sa_family == AF_INET)
        {
            tmpAddrPtr =& ((struct sockaddr_in *) ifa->ifa_addr)->sin_addr;
            char address_buffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, address_buffer, INET_ADDRSTRLEN);

            int count = 0;
            text_output = "IPv4 (" + static_cast<string>(ifa->ifa_name) + ")";

            cout << bold() << text_output << bold_end() << ": " << address_buffer <<  endl;
        }
        else if (ifa->ifa_addr->sa_family == AF_INET6 && on_ip6 == 1)
        {
            tmpAddrPtr =& ((struct sockaddr_in6 *) ifa->ifa_addr)->sin6_addr;
            char address_buffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, address_buffer, INET6_ADDRSTRLEN);

            int count = 0;
            text_output = "IPv6 (" + (string)ifa->ifa_name + ")";

            cout << bold() << text_output << bold_end() << ": " << address_buffer <<  endl;
        }
    }
    if (text_output.length() > 1) separator("");
    if (ifAddrStruct != NULL) freeifaddrs(ifAddrStruct);
}

void all_network()
{
    /*
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

    for(ifa = ifAddrStruct;  ifa != NULL; ifa = ifa->ifa_next)
    {
        if (!ifa->ifa_addr) continue;
        if (ifa->ifa_addr->sa_family == AF_INET)
        {
            char address_buffer[INET_ADDRSTRLEN];
            char mask_buffer[INET_ADDRSTRLEN];

            tmpAddrPtr = &((struct sockaddr_in *)(ifa->ifa_addr))->sin_addr;
            inet_ntop(AF_INET, tmpAddrPtr, address_buffer, INET_ADDRSTRLEN);

            tmpAddrPtr = &((struct sockaddr_in *)(ifa->ifa_netmask))->sin_addr;
            inet_ntop(AF_INET, tmpAddrPtr, mask_buffer, INET_ADDRSTRLEN);

            tmpMask = ((struct sockaddr_in *)(ifa->ifa_netmask))->sin_addr.s_addr;

            address_output = "IPv4    (" + static_cast<string>(ifa->ifa_name) + ")";
            netmask_output = "Netmask (" + static_cast<string>(ifa->ifa_name) + ")";

            /*
                OUTPUT
            */

            cout << bold() << address_output << bold_end() << ": " << address_buffer << endl;
            cout << bold() << netmask_output << bold_end() << ": " << mask_buffer <<  endl;

            if (static_cast<string>(ifa->ifa_name) == "lo")
            {
                if (address_output.length() > 1) separator("");
                continue;
            }
            else
            {
                string ip_name = get_gateway( static_cast<string>(ifa->ifa_name) );
                cout << bold() << "Gateway (" + static_cast<string>(ifa->ifa_name) + ")" << bold_end() << ": " << ip_name << endl;
            }

            /*
                OUTPUT END
            */

            if (address_output.length() > 1) separator("");
        }
    }
    if (ifAddrStruct != NULL) freeifaddrs(ifAddrStruct);
}

string get_gateway(string input_value)
{
    fstream file;

    string interface;
    string ip_name;
    string ip_name_buf;
    string ip_name_buf2;
    string ipv4_octet[4];
    string ip_output[4];


    int ip_converted[4];
    int nr = 0;

    file.open( home_path() + "/.systeminfo-files/systeminfo-gateway.txt", ios::in );
    if (file.good() == true)
    {
        while (!file.eof())
        {
            nr++;
            getline(file, interface);

            if (interface == input_value)
            {
                ip_name = open_file(home_path()+"/.systeminfo-files/systeminfo-gateway.txt", nr + 1);

                if (ip_name.length() == 8)
                {
                    ip_name_buf = ip_name;                         //
                    ipv4_octet[0] = ip_name_buf.erase( 0, 6 );     // first octed
                    ip_converted[0] = hex2dec(ipv4_octet[0]);      //
                    ip_output[0] = int_to_str(ip_converted[0]);    //

                    ip_name_buf = ip_name;                         //
                    ipv4_octet[1] = ip_name_buf.erase( 0, 4 );     //
                    ipv4_octet[1] = ipv4_octet[1].erase( 2, 4 );   // second octed
                    ip_converted[1] = hex2dec(ipv4_octet[1]);      //
                    ip_output[1] = int_to_str(ip_converted[1]);    //

                    ip_name_buf = ip_name;                         //
                    ipv4_octet[2] = ip_name_buf.erase( 0, 2 );     //
                    ipv4_octet[2] = ipv4_octet[2].erase( 2, 6 );   // third octed
                    ip_converted[2] = hex2dec(ipv4_octet[2]);      //
                    ip_output[2] = int_to_str(ip_converted[2]);    //

                    ip_name_buf = ip_name;                         //
                    ipv4_octet[3] = ip_name_buf.erase( 2, 7 );     // fourth octed
                    ip_converted[3] = hex2dec(ipv4_octet[3]);      //
                    ip_output[3] = int_to_str(ip_converted[3]);    //

                    return ip_output[0] + "." + ip_output[1] + "." + ip_output[2] + "." + ip_output[3];
                }

            }
        }
    }
    file.close();

    return "N/A";
}

int hex2dec (string hexadecimal)
{
    int decimal = strtol(hexadecimal.c_str(), NULL, 16);

    return decimal;
}