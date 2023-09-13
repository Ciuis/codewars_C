/*
Given some points(array A) on the same line, determine the minimum number of line segments with length L needed to cover all of the given points. A point is covered if it is located inside some segment or on its bounds.
Example
        For A = [1, 3, 4, 5, 8] and L = 3, the output should be 2.
Check out the image below for better understanding:
For A = [1, 5, 2, 4, 3] and L = 1, the output should be 3.
segment1: 1-2(covered points 1,2),
segment2: 3-4(covered points 3,4),
segment3: 5-6(covered point 5)
For A = [1, 10, 100, 1000] and L = 1, the output should be 4.
segment1: 1-2(covered point 1),
segment2: 10-11(covered point 10),
segment3: 100-101(covered point 100),
segment4: 1000-1001(covered point 1000)
Input/Output
[input] integer array A
        Array of point coordinates on the line (all points are different).
Constraints:
1 ≤ A.length ≤ 50,
-5000 ≤ A[i] ≤ 5000.
[input] integer L
Segment length, a positive integer.
Constraints: 1 ≤ L ≤ 100.
[output] an integer
The minimum number of line segments that can cover all of the given points.*/

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

unsigned segment_cover (unsigned nb_points, const int A[nb_points], unsigned L) {
    unsigned line_count = 1;
    int* points = malloc(nb_points * sizeof(int));
    for (int i = 0; i < nb_points; ++i) { points[i] = A[i]; }

    qsort(points, nb_points, sizeof(int), compare);

    int last = points[0];
    for (unsigned i = 0; i < nb_points; ++i) {
        if (points[i] - last > L) { ++line_count; last = points[i]; }
    }

    free(points);

    return line_count;
}