/*Write a function which calculates the average of the numbers in a given list.

Note: Empty arrays should return 0.*/

double find_average(const double array[/* length */], unsigned length) {
    if (length  == 0) return 0.00;
    double res = 0;
    for (unsigned i = 0; i < length; ++i) {
        res += array[i];
    }
    return res / length;
}
