/*Given a non-negative integer n, write a function to_binary/ToBinary which returns that number in a binary format.

Example:

to_binary(1)  */
/* should return 1 *//*

to_binary(5)  */
/* should return 101 *//*

to_binary(11) */
/* should return 1011 */
#include <stdio.h>

unsigned long long to_binary(unsigned short num);

int main(void) {
    int num = 11;
    printf("%u", to_binary(num));
}

unsigned long long to_binary(unsigned short num) {
    return (num == 0 || num == 1 ? num : ((num % 2) + 10 * to_binary(num / 2)));
}