/*
The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255. Any values that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

The following are examples of expected output values:

char output[7] = {0};

rgb(255, 255, 255, output);
output == "FFFFFF";

rgb(255, 255, 300, output);
output == "FFFFFF";

rgb(0, 0, 0, output);
output == "000000";

rgb(148, 0, 211, output);
output == "9400D3";
*/

#include <stdlib.h>
#include <stdio.h>

int rgb(int r, int g, int b, char *output);

int main() {
    int r = 255;
    int g = 155;
    int b = -20;

    char* hex_code = calloc(7, 1);

    rgb(r, g, b, hex_code);

    printf("%s", hex_code);
}




int rgb(int r, int g, int b, char *output) {

    if (r < 0) r = 0; if (r > 255) r = 255;
    if (g < 0) g = 0; if (g > 255) g = 255;
    if (b < 0) b = 0; if (b > 255) b = 255;

    sprintf(output, "%02X%02X%02X", r, g, b);

    return 0;
}



/*
char* to_hex(int n) {
    int tmp = 0;

    char* out = calloc(3, 1);

    while (n > 0) {
        switch (n % 16) {
            case 10:
                out[tmp] = 'A';
                break;
            case 11:
                out[tmp] = 'B';
                break;
            case 12:
                out[tmp] = 'C';
                break;
            case 13:
                out[tmp] = 'D';
                break;
            case 14:
                out[tmp] = 'E';
                break;
            case 15:
                out[tmp] = 'F';
                break;
            default:
                out[tmp] = (n % 16) + 48;
        }
        n  = n / 16;
        tmp++;
    }

    return out;
}
*/