/*
Magpies are my favourite birds
        Baby ones even more so...
It is a little known fact^ that the black & white colours of baby magpies differ by at least one place and at most two places from the colours of the mother magpie.
So now you can work out if any two magpies may be related.
...and Quardle oodle ardle wardle doodle the magpies said
        Kata Task
        Given the colours of two magpies, determine if one is a possible child or grand-child of the other.
Notes
        Each pair of birds being compared will have same number of colour areas
B = Black
W = White
Example
        Given these three magpies
        Magpie 1  BWBWBW
        Magpie 2  BWBWBB
        Magpie 3  WWWWBB
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool child (const char *bird1, const char *bird2);
bool grandchild (const char *bird1, const char *bird2);
int check_diff(const char *bird1, const char *bird2);

int main(void) {
    char* bird1 = "B";
    char* bird2 = "W";

    printf("%d %d", child(bird1, bird2), grandchild(bird1, bird2));

    return 0;
}

int check_diff(const char *bird1, const char *bird2) {
    int x = 0;
    for (int i = 0; bird1[i] != '\0' && bird2[i] != '\0'; ++i) {
        if (bird1[i] != bird2[i])
            ++x;
    }

    return x;
}

bool child (const char *bird1, const char *bird2) {
    if (strcmp(bird1, bird2) == 0)
        return false;
    return (check_diff(bird1, bird2) < 3 ? true : false);
}

bool grandchild (const char *bird1, const char *bird2) {
    if (strlen(bird1) == 1 && strlen(bird2) == 1 && strcmp(bird1, bird2) != 0) return false;
    return (check_diff(bird1, bird2) < 5 ? true : false);
}


/*
_Bool child (char *x, char *y) { int c=0; for (;*x;) c+=*x++!=*y++; return c&&c<3; }
_Bool grandchild (char *x, char *y) { int c=0,n=0; for (;*x;++n) c+=*x++!=*y++; return n>1?c<5:!c; }*/
