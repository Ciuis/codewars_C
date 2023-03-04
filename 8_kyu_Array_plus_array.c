#include <stddef.h>
#include <stdio.h>

long arr_plus_arr(const int *a,  const int *b, size_t na, size_t nb);

int main(void) {
    const int a[] = { 1, 2, 3 };
    const int b[] = { 4, 5, 6 };
    size_t na = 3;
    size_t nb = 3;

    printf("%d", arr_plus_arr(a, b, na, nb));
}

long arr_plus_arr(const int *a,  const int *b, size_t na, size_t nb) {
    long res = 0;
    for(int i = 0; i < na; ++i) {
        res += a[i];
    }
    for (int i = 0; i < nb; ++i) {
        res += b[i];
    }
    return res;
}


/*
long arr_plus_arr(const int *a,  const int *b, size_t na, size_t nb)
{
    long t = 0;
    while (na--) t += *a++;
    while (nb--) t += *b++;
    return t;
}*/
