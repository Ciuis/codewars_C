/*Task

        Given a point in a Euclidean plane (x and y), return the quadrant the point exists in: 1, 2, 3 or 4 (integer). x and y are non-zero integers, therefore the given point never lies on the axes.
Examples

(1, 2)     => 1
(3, 5)     => 1
(-10, 100) => 2
(-1, -9)   => 3
(19, -56)  => 4

Reference
[Quadrants] Quadrants

        There are four quadrants:

First quadrant, the quadrant in the top-right, contains all points with positive X and Y
Second quadrant, the quadrant in the top-left, contains all points with positive X, but negative Y
Third quadrant, the quadrant in the bottom-left, contains all points with negative X, but positive Y
Fourth quadrant, the quadrant in the bottom-right, contains all points with negative X an*//*d Y*/

enum quadrants {I=1, II, III, IV};

enum quadrants quadrant(int x, int y) {
    return  x < 0 && y < 0 ? III :
            x < 0 && y > 0 ? II :
            x > 0 && y < 0 ? IV :
            I;
}

/*
enum quadrants quadrant(int x, int y) {
    return x > 0 ? y > 0 ? 1 : 4 : y > 0 ? 2 : 3;
}*/
