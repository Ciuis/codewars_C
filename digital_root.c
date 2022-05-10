/*Digital root is the recursive sum of all the digits in a number.

Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.
Examples

16  -->  1 + 6 = 7
942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2*/

/*   int digital_root(int Z) {
       return --Z % 9 + 1;
   }*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digital_root(int n);

int main() {
    int n = 493193;

    printf("%d ", digital_root(n));
}

int digital_root(int n) {
    /*int sum = (n > 9) ? n % 10 + digital_root(n / 10) : n;*/

    int sum = 0;

    while (n > 0 || sum > 9) {
        if (n == 0) {
            n = sum;
            sum = 0;
        }

        sum += n % 10;
        n /= 10;
    }

    return sum;

}