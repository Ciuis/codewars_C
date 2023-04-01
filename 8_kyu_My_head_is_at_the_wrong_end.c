/*You're at the zoo... all the meerkats look weird. Something has gone terribly wrong - someone has gone and switched their heads and tails around!

Save the animals by switching them back. You will be given an array which will have three values (tail, body, head). It is your job to re-arrange the array so that the animal is the right way round (head, body, tail).

Same goes for all the other arrays/lists that you will get in the tests: you have to change the element positions with the same exact logics

Simples!*/

#include <stddef.h> // NULL
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


const char **fix_the_meerkat(const char **arr) {
    char **result = malloc(3 * sizeof(char *));

    result[0] = arr[2];
    result[1] = arr[1];
    result[2] = arr[0];

    return result;
}