#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_square(int n);

int main() {
    int n = 144;

    printf("%d", is_square(n));
    return 0;
}

bool is_square(int n) {
    int m = sqrt(n);
    printf("%f\n", m);
    int m2 = pow(m, 2);
    printf("%d\n", m2);

    if (m * m != (float)n) {
        return false;
    }

    return true;
}