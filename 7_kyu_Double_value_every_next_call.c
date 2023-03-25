/*
This kata is about a function that should return different values.

On the first call it must be 1, on the second and others - it must be a double from previous value. */

unsigned get_number (void) {
    static unsigned i = 1;
    unsigned res = i;
    res *= 2;

    return res;
}