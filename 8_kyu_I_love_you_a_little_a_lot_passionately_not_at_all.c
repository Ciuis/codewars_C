/*
Who remembers back to their time in the schoolyard, when girls would take a flower and tear its petals, saying each of the following phrases each time a petal was torn:

"I love you"
"a little"
"a lot"
"passionately"
"madly"
"not at all"

If there are more than 6 petals, you start over with "I love you" for 7 petals, "a little" for 8 petals and so on.

When the last petal was torn there were cries of excitement, dreams, surging thoughts and emotions.

Your goal in this kata is to determine which phrase the girls would say at the last petal for a flower of a given number of petals. The number of petals is always greater than 0.
*/

#include <stddef.h>
#include <stdio.h>

const char* how_much_i_love_you(int nb_petals);

int main(void) {
    int nb_petals = 17;

    printf("%s", how_much_i_love_you(nb_petals));
}

const char* how_much_i_love_you(int nb_petals) {
    while (nb_petals > 6) {
        nb_petals -= 6;
    }
    switch (nb_petals) {
        case 1:
            return "I love you";
        case 2:
            return "a little";
        case 3:
            return "a lot";
        case 4:
            return "passionately";
        case 5:
            return "madly";
        case 6:
            return "not at all";
    }
}


/* Much better
const char* how_much_i_love_you(int nb_petals) {
    const char *phrases[6] = {
            "I love you",
            "a little",
            "a lot",
            "passionately",
            "madly",
            "not at all"
    };

    return phrases[(nb_petals - 1) % 6];
}*/

/*
const char* how_much_i_love_you(int nb_petals) {
    char* PHRASES[] = {"I love you", "a little", "a lot", "passionately", "madly", "not at all"};
    return PHRASES[(nb_petals - 1) % (sizeof(PHRASES)/sizeof(char *))];
}*/
