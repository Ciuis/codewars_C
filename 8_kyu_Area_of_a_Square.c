/*Complete the function that calculates the area of the red square, when the length of the circular arc A is given as the input. Return the result rounded to two decimals.

Graph

        Note: use the π value provided in your language (Math::PI, M_PI, math.pi, etc)*/
#include <stdio.h>
#include <math.h>


double square_area(double arc) {
    return round(((arc * arc) / (PI * PI))*4 * 100)/100;
}
