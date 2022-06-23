/*Write a function that outputs the transpose of a matrix - a new matrix where the columns and rows of the original are swapped.

For example, the transpose of:

| 1 2 3 |
| 4 5 6 |

is

| 1 4 |
| 2 5 |
| 3 6 |

The input to your function will be an array of matrix rows. You can assume that each row has the same length, and that the height and width of the matrix are both positive.*/
#include <stddef.h>

void transpose_matrix (
        size_t rows, size_t cols,
        const int matrix[rows][cols],
        int transpose[cols][rows]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }
}