/*There was a test in your class and you passed it. Congratulations!
But you're an ambitious person. You want to know if you're better than the average student in your class.

You receive an array with your peers' test scores. Now calculate the average and compare your score!

Return True if you're better, else False!
Note:

Your points are not included in the array of your class's points. For calculating the average point you may add your point to the given array!*/

#include <stdbool.h>

bool better_than_average(const int class_points[], int class_size, int your_points) {
    int avg_score = 0;

    for (int i = 0; i < class_size; ++i) {
        avg_score += class_points[i];
    }

    avg_score = (avg_score + your_points) / (class_size + 1);

    return your_points > avg_score ? true : false;
}