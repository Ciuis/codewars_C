/*
In this kata, you should calculate the type of triangle with three given sides a, b and c (given in any order).

If each angle is less than 90°, this triangle is acute and the function should return 1.

If one angle is strictly 90°, this triangle is right and the function should return 2.

If one angle is more than 90°, this triangle is obtuse and the function should return 3.

If three sides cannot form a triangle, or one angle is 180° (which turns the triangle into a segment) - the function should return 0.

Three input parameters are sides of given triangle. All input values are non-negative floating point or integer numbers (or both, depending on the language).*/

#include <math.h>
#include <stdio.h>

#define PI 3.1415

int triangleType(int a, int b, int c);

int main(void) {
    int a = 3;
    int b = 4;
    int c = 5;
    printf("%d", triangleType(a, b, c));

    return 0;
}

int triangleType(int a, int b, int c) {
    if (a + b <= c || a + c <= b || b + c <= a) return 0;

    double aAngle = round(acos((b * b + c * c - a * a) / (2.0 * b * c)) * 180.0 / PI);
    double bAngle = round(acos((a * a + c * c - b * b) / (2.0 * a * c)) * 180.0 / PI);
    double cAngle = round(acos((a * a + b * b - c * c) / (2.0 * a * b)) * 180.0 / PI);

    if (aAngle < 90 && bAngle < 90 && cAngle < 90) return 1;
    if (aAngle == 90 || bAngle == 90 || cAngle == 90) return 2;
    if (aAngle > 90 || bAngle > 90 || cAngle > 90) return 3;

    return 0;
}