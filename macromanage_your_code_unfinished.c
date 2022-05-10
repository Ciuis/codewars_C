#include <stdio.h>

char* stringify_int(int a) {
    return 0;
}

char* stringify_char(char* a) {
    return 0;
}

char* stringify_float(float a) {
    return 0;
}

#define stringify(X)                    \
        _Generic((X),                   \
                int: stringify_int,     \
                char*: stringify_char,  \
                float: stringify_float, \
                default: stringify_char \
                ) (X)

int main() {

}