/*Write a function to split a string and convert it into an array of words.
Examples (Input ==> Output):

"Robin Singh" ==> ["Robin", "Singh"]

"I love arrays they are my favorite" ==> ["I", "love", "arrays", "they", "are", "my", "favorite"]

Words will be separated by exactly one space, without leading or trailing spaces.

There will only be letters and spaces in the input string.*/

#include <stdlib.h>
#include <string.h>

size_t count_words (const char *words) {
    size_t count = 0;
    int in_word = 0;
    for (size_t i = 0; words[i] != '\0'; ++i) {
        if (words[i] == ' ') {
            in_word = 0;
        } else if (!in_word) {
            ++count;
            in_word = 1;
        }
    }
    return count;
}

void words_to_array (const char *words, char *words_array[]) {
    char* tmp_words = (char*)calloc(strlen(words), sizeof(char));
    strcpy(tmp_words, words);
    char* word = strtok(tmp_words, " ");
    size_t i = 0;

    while (word != NULL) {
        words_array[i] = (char*)calloc(strlen(word), sizeof(char));
        strcpy(words_array[i], word);
        word = strtok(NULL, " ");
        ++i;
    }
}
