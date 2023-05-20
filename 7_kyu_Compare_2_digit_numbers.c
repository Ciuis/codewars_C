/*You are given 2 two-digit numbers. You should check if they are similar by comparing their numbers, and return the result in %.

Example:

compare(13,14)=50%;
compare(23,22)=50%;
compare(15,51)=100%;
compare(12,34)=0%.

In C language you should return P_100, P_50 and P_0 instead of strings "100%", "50%", "0%"*/

#include <stdio.h>

enum percent {P_100, P_50, P_0};

enum percent compare(unsigned short a, unsigned short b) {
    return a == b ? P_100 : a % 10 == b / 10 && a / 10 == b % 10 ? P_100 : a % 10 == b / 10 || a / 10 == b % 10 || a / 10 == b / 10 || a % 10 == b % 10 ? P_50 : P_0;
}