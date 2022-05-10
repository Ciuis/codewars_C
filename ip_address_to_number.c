/*An IPv4 address is a 32-bit number that identifies a device on the internet.

While computers read and write IP addresses as a 32-bit number, we prefer to read them in dotted-decimal notation, which is basically the number split into 4 chunks of 8 bits, converted to decimal, and delmited by a dot.

In this kata, you will create the function ipToNum that takes an ip address and converts it to a number, as well as the function numToIp that takes a number and converts it to an IP address string. Input will always be valid.
Conversion Example

//original IP address
192.168.1.1

//breaks down into 4 binary octets
11000000 . 10101000 . 00000001 . 00000001

//which are merged together (unsigned 32-bit binary)
11000000101010000000000100000001

//and finally converted to base 10
3232235777

Note that the binary octets are unsigned (so we can't have negative numbers).
Code Examples
ipToNum

ipToNum('192.168.1.1') //returns 3232235777
ipToNum('10.0.0.0') //returns 167772160
ipToNum('176.16.0.1') //returns 2953838593

numToIp

numToIp(3232235777) //returns '192.168.1.1'
numToIp(167772160) //returns '10.0.0.0'
numToIp(2953838593) //returns '176.16.0.1'

nested

numToIp(ipToNum('192.168.1.1')) //returns '192.168.1.1'
ipToNum(numToIp(3232235777)) //returns 3232235777*/

#include <inttypes.h>
#include <stdio.h>

uint32_t IP_to_num (const char *IP);
char *num_to_IP (uint32_t num, char *IP);

int main() {
    char* ip = "255.255.255.255";
    IP_to_num(ip);
    uint32_t dec = 4294967295;
    char* IP;
    num_to_IP(dec, IP);
}

uint32_t IP_to_num (const char *IP) {
    unsigned n[4];
    uint32_t bin = 0;

    sscanf(IP,"%d.%d.%d.%d", &n[0], &n[1], &n[2], &n[3]);

    for (int i = 0; i < 4; ++i) {
        bin |= n[i] << (8 * (3 - i));
    }

    printf("%u\n", bin);

    return bin;
}

char *num_to_IP (uint32_t num, char *IP) {
    unsigned char bts[4];

    bts[0] = num & 0xFF;
    bts[1] = (num >> 8) & 0xFF;
    bts[2] = (num >> 16) & 0xFF;
    bts[3] = (num >> 24) & 0xFF;

    snprintf(IP, 4, "%d.%d.%d.%d", bts[3], bts[2], bts[1], bts[0]);
    *IP = '\0';
    return IP;
}

/**
* best practice
*/

/*
#include <inttypes.h>
#include <stdio.h>

union ip {
    uint32_t addr;
    uint8_t byte[4];
} x;

uint32_t IP_to_num (const char *IP)
{
    sscanf (IP, "%hhu.%hhu.%hhu.%hhu", &x.byte[3], &x.byte[2], &x.byte[1], &x.byte[0]);
    return x.addr;
}

char *num_to_IP (uint32_t num, char *IP)
{
    x.addr = num;
    sprintf (IP, "%hhu.%hhu.%hhu.%hhu", x.byte[3], x.byte[2], x.byte[1], x.byte[0]);
    return IP;
}
 */
