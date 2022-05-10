/*Create a function that takes a string as a parameter and does the following, in this order:

Replaces every letter with the letter following it in the alphabet (see note below)
Makes any vowels capital
Makes any consonants lower case

Note:

the alphabet should wrap around, so Z becomes A
in this kata, y isn't considered as a vowel.

So, for example the string "Cat30" would return "dbU30" (Cat30 --> Dbu30 --> dbU30)*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *change_it_up (char *str_out, const char *str_in);

int main() {
    char* str_in = "ruC!ie2cuWvEiR^I8Usx!Y5*mriW4hOIBs-";
    char* str_out = malloc(strlen(str_in) * sizeof(char));
    printf("%s", change_it_up(str_out, str_in));
}

char *change_it_up (char *str_out, const char *str_in) {
// write to str_out and return it
    for (int i = 0; i < strlen(str_in); i++) {
        if((str_in[i] >= 'A' && str_in[i] <= 'Z') || (str_in[i] >= 'a' && str_in[i] <= 'z')) {
            switch (tolower(str_in[i]) + 1) {
                case '{':
                    str_out[i] = 'A';
                    break;
                case 'a':
                    str_out[i] = 'A';
                    break;
                case'e':
                    str_out[i] = 'E';
                    break;
                case 'i':
                    str_out[i] = 'I';
                    break;
                case 'o':
                    str_out[i] = 'O';
                    break;
                case 'u':
                    str_out[i] = 'U';
                    break;
                default:
                    str_out[i] = tolower((char)str_in[i] + 1);
                    break;
            }

        } else {
            str_out[i] = str_in[i];
        }
    }

    return str_out;

}

/* clever way
char *change_it_up (char *str_out, const char *str_in)
{
    char *retval = str_out;

    for (char ch; (ch = *str_in); str_in++, str_out++) {
        if (isalpha(ch)) {
            ch = 'a' + ((tolower(ch) - 'a' + 1) % 26);
            if (strchr("aeiou", ch))
                ch = toupper(ch);
        }
        *str_out = ch;
    }
    *str_out = '\0';
    return retval;
}*/
