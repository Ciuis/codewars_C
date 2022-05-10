/*Write the following function:

double area_of_polygon_inside_circle(double circle_radius, int number_of_sides);

It should calculate the area of a regular polygon of numberOfSides, number-of-sides, or number_of_sides sides inside a circle of radius circleRadius, circle-radius, or circle_radius which passes through all the vertices of the polygon (such circle is called circumscribed circle or circumcircle). The answer should be a number rounded to 3 decimal places.

Input :: Output Examples

area_of_polygon_inside_circle(3, 3); // => 11.691

area_of_polygon_inside_circle(5.8, 7); // => 92.053

area_of_polygon_inside_circle(4, 5); // => 38.042*/
#include <stdio.h>
#include <math.h>

double PI = 3.141592653589793; // Use this value as pi in your calculations if necessary

double area_of_polygon_inside_circle(double circle_radius, int number_sides);

int main() {
    double rad = 3;
    int nSides = 3;
    printf("%f", area_of_polygon_inside_circle(rad, nSides));

}

double area_of_polygon_inside_circle(double circle_radius, int number_sides) {
    double area = (double)number_sides/2 * pow(circle_radius, 2) * sin((2 * PI)/number_sides);

    return round(area * 1000) / 1000;
}
