#include <math.h>

unsigned amount_of_pages(unsigned s) {
    for (unsigned i = 1, t = 0; ; i++)
        if ((t += log10(i) + 1) == s)
            return i;