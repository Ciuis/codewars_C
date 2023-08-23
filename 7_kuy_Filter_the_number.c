/*Filter the number
Oh, no! The number has been mixed up with the text. Your goal is to retrieve the number from the text, can you return the number back to its original state?
Task
Your task is to return a number from a string.
Details
You will be given a string of numbers and letters mixed up, you have to return all the numbers in that string in the order they occur.*/

#include <stdio.h>
#include <ctype.h>

long long filter_string(const char *value) {
    long long res = 0;
    for (int i = 0; value[i] != '\0'; ++i) {
        if (isdigit(value[i])) {
            res = res * 10 + (value[i] - '0');
        }
    }
    return res;
}

int main(void) {
    char* v = "12Fghf3";
    filter_string(v);
    return 0;
}