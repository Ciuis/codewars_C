/*
Your coworker was supposed to write a simple helper function to capitalize a string (that contains a single word) before they went on vacation.

Unfortunately, they have now left and the code they gave you doesn't work. Fix the helper function they wrote so that it works as intended (i.e. make the first character in the string "word" upper case).

Don't worry about numbers, special characters, or non-string types being passed to the function. The string lengths will be from 1 character up to 10 characters, but will never be empty.*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *capitalize_word (char *word);

int main(void) {
    char* word = "word";
    printf("%s", capitalize_word(word));

}

char *capitalize_word (char *word) {
    //word[0] = (char)toupper(word[0]); //  something goes wrong here !
    char* ch = (char*)malloc(sizeof(word));
    ch[0] = (char)toupper(word[0]);
    for (int i = 1; word[i] != '\0'; ++i)  ch[i] = word[i];
    ch[strlen(word)] = '\0';
    return ch;
}