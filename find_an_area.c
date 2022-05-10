/*You have an array or list of coordinates or points (e.g. [ [1, 1], [3, 4], ... , [5, 2] ]), and your task is to find the area under the graph defined by these points (limited by x of the first and last coordinates as left and right borders, y = 0 as the bottom border and the graph as top border).

Notes:

x can be negative;
x of the next pair of coordinates will always be greater then previous one;
y >= 0;
the array will contain more than 2 coordinates.

Example

        x=1 (left border)               x=5 (right border)
|                      x,y      |
|                    /\         |
|                   /  \        |
|    x,y           /    \       |
|   /\            /      \      |
|  /  \    x,y   /        \     |
| /    \  /\    /          \    |
|/      \/  \  /            \   |
|x,y    x,y  \/              \  |
|            x,y              \ |
|_____________________________ \x,y_____ y=0 (bottom border)

The required area:

|                               |
|                    /\         |
|                   /\\\        |
|                  /\\\\\       |
|   /\            /\\\\\\\      |
|  /\\\          /\\\\\\\\\     |
| /\\\\\  /\    /\\\\\\\\\\\    |
|/\\\\\\\/\\\  /\\\\\\\\\\\\\   |
|\\\\\\\\\\\\\/\\\\\\\\\\\\\\\  |
|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ |
|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\|

Definition of points

struct Point {
    int x, y;
};*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x, y;
};

double find_area (int n, const struct Point points[n]);

int main() {
    struct Point p[] = {{-3, 2}, {3, 5}};
    int n = 2;

    find_area(n, p);
}

double find_area (int n, const struct Point points[n]) {
    double area = 0;

    for (int i = 1; i < n; ++i) {
        area += (points[i - 1].y + points[i].y) * (points[i].x - points[i - 1].x);
    }

    area *= 0.5;
    printf("%f", area);

    return area;

}