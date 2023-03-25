/*
You'll be given a string, and have to return the sum of all characters as an int. The function should be able to handle all printable ASCII characters.

Examples:

uniTotal("a") == 97
uniTotal("aaa") == 291
*/

int uni_total(const char *s) {
    int res = 0;
    for (; *s != '\0'; s++) {
        res += (int)*s;
    }
    return res;
}

//return *s ? *s + uni_total(s+1) : 0;