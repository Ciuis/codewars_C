/*
No Story
No Description
Only by Thinking and Testing
Look at the results of the testcases, and guess the code!*/

#include <math.h>
#include <string.h>

unsigned how_many_word (const char *string) {
    int incr = 0; double a = .0;
    for (size_t i = 0; i < strlen(string); ++i) {
        if ((string[i] == 'w' || string[i] == 'W') && incr == 0) {
            incr += 1;
            a += .25;
        }
        if ((string[i] == 'o' || string[i] == 'O' || *string == '0') && incr == 1) {
            incr += 1;
            a += .25;
        }
        if ((string[i] == 'r' || string[i] == 'R') && incr == 2) {
            incr += 1;
            a += .25;
        }
        if ((string[i] == 'd' || string[i] == 'D') && incr == 3) {
            incr = 0;
            a += .25;
        }
    }
    return floor(a);
}
