/*Create a function that takes a Roman numeral as its argument and returns its value as a numeric decimal integer. You don't need to validate the form of the Roman numeral.

Modern Roman numerals are written by expressing each decimal digit of the number to be encoded separately, starting with the leftmost digit and skipping any 0s. So 1990 is rendered "MCMXC" (1000 = M, 900 = CM, 90 = XC) and 2008 is rendered "MMVIII" (2000 = MM, 8 = VIII). The Roman numeral for 1666, "MDCLXVI", uses each letter in descending order.

Example:

solution('XXI'); // should return 21

Help:

Symbol    Value
I          1
V          5
X          10
L          50
C          100
D          500
M          1,000*/

#include <string.h>

unsigned decode_roman (const char *roman_number) {
    unsigned res = 0;
    int active_digit = 0, next_digit = 0;
    unsigned len = strlen(roman_number);

    switch (roman_number[len]) {
        case 'I': {active_digit = 1; break;}
        case 'V': {active_digit = 5; break;}
        case 'X': {active_digit = 10; break;}
        case 'L': {active_digit = 50; break;}
        case 'C': {active_digit = 100; break;}
        case 'D': {active_digit = 500; break;}
        case 'M': {active_digit = 1000; break;}
    }
    res = active_digit;
    while (len > 0) {
        switch (roman_number[len - 1]) {
            case 'I': {next_digit = 1; break;}
            case 'V': {next_digit = 5; break;}
            case 'X': {next_digit = 10; break;}
            case 'L': {next_digit = 50; break;}
            case 'C': {next_digit = 100; break;}
            case 'D': {next_digit = 500; break;}
            case 'M': {next_digit = 1000;break;}
        }
        if (next_digit < active_digit) {
            res -= next_digit;
        } else {
            res += next_digit;
        }
        --len;
        active_digit = next_digit;
    }

    return res;
}


/*
const unsigned values[89] = {0,['I'] = 1,['V'] = 5,['M'] = 1000,['C'] = 100,['D'] = 500,['L'] = 50,['X'] = 10};

unsigned decode_roman (const char *numbers)
{
    unsigned result = 0, i = 0;
    while(numbers[i]){
        result += values[numbers[i]] * (1 - (2 * (values[numbers[i]] < values[numbers[i+1]])));
        i++;
    }
    return result;
}*/
