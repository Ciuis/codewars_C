/*
Define n!! as

        n!! = 1 * 3 * 5 * ... * n if n is odd,

n!! = 2 * 4 * 6 * ... * n if n is even.

Hence 8!! = 2 * 4 * 6 * 8 = 384, there is no zero at the end. 30!! has 3 zeros at the end.

For a positive integer n, please count how many zeros are there at the end of n!!.

Example:

30!! = 2 * 4 * 6 * 8 * 10 * ... * 22 * 24 * 26 * 28 * 30
30!! = 42849873690624000 (3 zeros at the end)*/

int count_zeros_n_double_fact(int n) {
    if (n % 2 != 0) {
        return 0;
    }
    int m = 0;
    while (n >= 10) {
        m += n / 10;
        n /= 5;
    }

    return m;
}