/*
I've got a crazy mental illness. I dislike numbers a lot. But it's a little complicated: The number I'm afraid of depends on which day of the week it is... This is a concrete description of my mental illness:
Monday --> 12
Tuesday --> numbers greater than 95
Wednesday --> 34
Thursday --> 0
Friday --> numbers divisible by 2
Saturday --> 56
Sunday --> 666 or -666
Write a function which takes a string (day of the week) and an integer (number to be tested) so it tells the doctor if I'm afraid or not. (return a boolean)*/

#include <stdbool.h>
#include <string.h>

bool am_i_afraid(const char *day, int num);

int main(void) {
    return 0;
}

bool am_i_afraid(const char *day, int num) {
    if (strcmp(day, "Monday") == 0 && num == 12) return true;
    if (strcmp(day, "Tuesday") == 0 && num > 95) return true;
    if (strcmp(day, "Wednesday") == 0 && num == 34) return true;
    if (strcmp(day, "Thursday") == 0 && num == 0) return true;
    if (strcmp(day, "Friday") == 0 && num % 2 == 0) return true;
    if (strcmp(day, "Saturday") == 0 && num == 56) return true;
    if (strcmp(day, "Sunday") == 0 && (num == 666 || num == -666)) return true;
    return false;
}