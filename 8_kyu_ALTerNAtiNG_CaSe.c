/*altERnaTIng cAsE <=> ALTerNAtiNG CaSe

Define String.prototype.toAlternatingCase (or a similar function/method such as to_alternating_case/toAlternatingCase/ToAlternatingCase in your selected language; see the initial solution for details) such that each lowercase letter becomes uppercase and each uppercase letter becomes lowercase. For example:

to_alternating_case("hello world"); // => "HELLO WORLD"
to_alternating_case("HELLO WORLD"); // => "hello world"
to_alternating_case("hello WORLD"); // => "HELLO world"
to_alternating_case("HeLLo WoRLD"); // => "hEllO wOrld"
to_alternating_case("12345"); // => "12345" (Non-alphabetical characters are unaffected)
to_alternating_case("1a2b3c4d5e"); // => "1A2B3C4D5E"
to_alternating_case("String.prototype.toAlternatingCase"); // => "sTRING.PROTOTYPE.TOaLTERNATINGcASE"

As usual, your function/method should be pure, i.e. it should not mutate the original string.*/
#include <stdlib.h>
#include <string.h>

char *to_alternating_case(const char *s) {
    char* res = (char*)calloc(strlen(s) + 1, sizeof(char));

    for (unsigned i = 0; i < strlen(s); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            res[i] = s[i] - 'a' + 'A';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            res[i] = s[i] - 'A' + 'a';
        } else res[i] = s[i];
    }

    return res;
}

/*
char *to_alternating_case(const char *s) {
    char *res = calloc(strlen(s) + 1, sizeof(char));
    for (char *p = res; *s != '\0'; p++, s++) *p = islower(*s) ? toupper(*s) : tolower(*s);
    return res;
}*/
