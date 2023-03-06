/*Create a function that converts US dollars (USD) to Chinese Yuan (CNY) . The input is the amount of USD as an integer, and the output should be a string that states the amount of Yuan followed by 'Chinese Yuan'
Examples (Input -> Output)

15  -> '101.25 Chinese Yuan'
465 -> '3138.75 Chinese Yuan'

The conversion rate you should use is 6.75 CNY for every 1 USD. All numbers should be represented as a string with 2 decimal places. (e.g. "21.00" NOT "21.0" or "21")*/
#include <stdio.h>
#include <stdlib.h>

char *USD_to_CNY (long long dollars, char *yuans);

int main(void) {
    long long dollars = 122978293824730344l;
    char yuans[100] = {0};
    printf("%s\n", USD_to_CNY(dollars, yuans));

}

char *USD_to_CNY (long long dollars, char *yuans) {
    long double y = (long long)dollars * 6.75L;
    sprintf(yuans, "%.2Lf Chinese Yuan", y); // write to yuans
    return yuans; // return it
}