/*
You probably know the "like" system from Facebook and other pages. People can "like" blog posts, pictures or other items. We want to create the text that should be displayed next to such an item.

Implement the function which takes an array containing the names of people that like an item. It must return the display text as shown in the examples:

[]                                -->  "no one likes this"
["Peter"]                         -->  "Peter likes this"
["Jacob", "Alex"]                 -->  "Jacob and Alex like this"
["Max", "John", "Mark"]           -->  "Max, John and Mark like this"
["Alex", "Jacob", "Mark", "Max"]  -->  "Alex, Jacob and 2 others like this"
return must be an allocated string
do not mutate input
        Note: For 4 or more names, the number in "and 2 others" simply increases.*/

#include <stdlib.h>
#include <stdio.h>

// result string must be a heap-allocated, nul-terminated string
// to be freed by the tests suite

char *likes(size_t n, const char *const names[n]) {
    char* result = malloc(sizeof(char) * 100);
    switch(n) {
        case 0:
            sprintf(result, "no one likes this");
            return result;
        case 1:
            sprintf(result, "%s likes this", names[0]);
            return result;
        case 2:
            sprintf(result, "%s and %s like this", names[0], names[1]);
            return result;
        case 3:
            sprintf(result, "%s, %s and %s like this", names[0], names[1], names[2]);
            return result;
        default:
            sprintf(result, "%s, %s and %d others like this", names[0], names[1], n - 2);
            return result;
    }
}