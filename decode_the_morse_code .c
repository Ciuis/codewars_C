/*
 In this kata you have to write a simple Morse code decoder. While the Morse code is now mostly superseded by voice and digital data communication channels, it still has its use in some applications around the world.
 The Morse code encodes every character as a sequence of "dots" and "dashes". For example, the letter A is coded as ·−, letter Q is coded as −−·−, and digit 1 is coded as ·−−−−. The Morse code is case-insensitive, traditionally capital letters are used. When the message is written in Morse code, a single space is used to separate the character codes and 3 spaces are used to separate words. For example, the message HEY JUDE in Morse code is ···· · −·−−   ·−−− ··− −·· ·.
 NOTE: Extra spaces before or after the code have no meaning and should be ignored.
 In addition to letters, digits and some punctuation, there are some special service codes, the most notorious of those is the international distress signal SOS (that was first issued by Titanic), that is coded as ···−−−···. These special codes are treated as single special characters, and usually are transmitted as separate words.
 Your task is to implement a function that would take the morse code as input and return a decoded human-readable string.
 For example:
 decode_morse(".... . -.--   .--- ..- -.. .") should return "HEY JUDE"
 NOTE: For coding purposes you have to use ASCII characters . and -, not Unicode characters.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};
const char *ascii[55] = {"A",  "B",    "C",    "D",   "E", "F",    "G",   "H",    "I",  "J",    "K",   "L",    "M",  "N",  "O",   "P",    "Q",    "R",   "S",   "T", "U",   "V",    "W",   "X",    "Y",    "Z",    "0",     "1",     "2",     "3",     "4",     "5",     "6",     "7",     "8",     "9",     ".",      ",",      "?",      "'",      "!",      "/",     "(",     ")",      "&",     ":",      ";",      "=",     "+",     "-",      "_",      "\"",     "$",       "@",      "SOS"};

char *decode_morse(const char* morse_code);

int main() {
    char* code = ".... . -.--   .--- ..- -.. .";

    //decode_morse(code);

    decode_morse(code);

}

char *decode_morse(const char* morse_code) {
    char* decoded_string = (char*)malloc(sizeof(char) * strlen(morse_code));
    int word_cnt = 0, spaces = 0, chars = 0, word_len = 0, word_num = 0;
    char word[10];

    for (; morse_code[word_cnt] == ' ' && morse_code[word_len + word_cnt] != '\0'; ++word_cnt) {
        ;
    }

    for (; word_cnt < strlen(morse_code);) {
        word_len = 0;
        strcpy(word, "");

        while (morse_code[word_len + word_cnt] != ' ' && morse_code[word_len + word_cnt] != '\0') {
            word[word_len] = morse_code[word_len + word_cnt];
            ++word_len;
        }

        while ((morse_code[word_len + word_cnt] == ' ' && morse_code[word_len + word_cnt] != '\0') && !word_len) {
            ++spaces;
            ++word_cnt;
            printf("%d\t%d", spaces, word_cnt);
        }

        if (spaces == 3 && morse_code[word_cnt] != '\0') {
            decoded_string[word_num] = ' ';
            ++word_num;
            spaces = 0;
            continue;
        }

        spaces = 0;

        if(!word_len) continue;
        word[word_len] = '\0';
        word_cnt += word_len;
        printf("word_cnt: %d\n", word_cnt);
        chars = 0;

        while (strcmp(word, morse[chars])) ++chars;

        for (int i = 0; i < ascii[chars][i] != '\0'; ++i) {
            decoded_string[word_num] = ascii[chars][i];
            ++word_num;
        }

        decoded_string[word_num] = '\0';
    }

    const char* ret;
    ret = decoded_string;

    return ret;
}

/*
 *
 * char *decode_morse(const char* morse_code)
    {
      // morse is always longer than plaintext so strlen(morse_code) buffer is big enough
      char *buf = calloc(strlen(morse_code), 1), *b = buf;
      char *copy = strdup(morse_code), *tok = strtok(copy, " ");
      while (tok)
      {
        for (int i = 0; i < sizeof(morse) / sizeof(morse[0]); i++)
        {
          if (!strcmp(tok, morse[i]))
          {
            strcpy(b, ascii[i]);
            b += strlen(ascii[i]);
            break;
          }
        }

        // previous strtok replaced 1st space found with terminator, so look for another space *(tok-1) to find words
        if ((tok = strtok(NULL, " ")) && *(tok-1) == ' ')
        {
          *b++ = ' ';
        }
      }

      free(copy);
      return buf;
    }
 */