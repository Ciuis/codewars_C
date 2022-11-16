/*
 * Inspired by the development team at Vooza, write the function that

accepts the name of a programmer, and
returns the number of lightsabers owned by that person.

The only person who owns lightsabers is Zach, by the way. He owns 18, which is an awesome number of lightsabers. Anyone else owns 0.

For example(Input --> Output):

"anyone else" --> 0
"Zach" --> 18
*/

#include <stdio.h>
#include <string.h>

int HowManyLightsabersDoYouOwn(const char *name);

int main() {
    char* name[10];

    scanf("%s", name);

    printf ("%d", HowManyLightsabersDoYouOwn(name));
}

int HowManyLightsabersDoYouOwn(const char *name) {
    int saber_cnt = 0;
    strcmp(name, "Zach") == 0 ? (saber_cnt = 18) : (saber_cnt = 0);

    return saber_cnt;
}