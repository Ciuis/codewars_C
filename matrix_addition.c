/*Write a function that accepts two square matrices (N x N two dimensional arrays), and return the sum of the two. Both matrices being passed into the function will be of size N x N (square), containing only integers.

How to sum two matrices:

Take each cell [n][m] from the first matrix, and add it with the same [n][m] cell from the second matrix. This will be cell [n][m] of the solution matrix.

Visualization:

|1 2 3|     |2 2 1|     |1+2 2+2 3+1|     |3 4 4|
|3 2 1|  +  |3 2 3|  =  |3+3 2+2 1+3|  =  |6 4 4|
|1 1 1|     |1 1 3|     |1+1 1+1 1+3|     |2 2 4|

Example

        matrixAddition(
[ [1, 2, 3],
[3, 2, 1],
[1, 1, 1] ],
//      +
[ [2, 2, 1],
[3, 2, 3],
[1, 1, 3] ] )

// returns:
[ [3, 4, 4],
[6, 4, 4],
[2, 2, 4] ]
 */

#include <stdlib.h>
#include <stdio.h>

int *matrix_addition(size_t n, int matrix_a[n][n], int matrix_b[n][n]);

int main() {
    int matrix_a[3][3] = {{0, 0, 3},
                          {1, 3, 2},
                          {4, 6, 9}};
    int matrix_b[3][3] = {{1, 2, 0},
                          {3, 2, 4},
                          {3, 2, 0}};
    size_t n = 3;

    matrix_addition(n, matrix_a, matrix_b);
}

int *matrix_addition(size_t n, int matrix_a[n][n], int matrix_b[n][n]) {
    int** matrix_c = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; ++i) {
        matrix_c[i] = (int*)malloc(n * sizeof(int) + 1);
    }


    int(*loc_1)[n] = matrix_a;
    int(*loc_2)[n] = matrix_b;
    int(*loc_3)[n] = matrix_c;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            loc_3[i][j] = loc_1[i][j] + loc_2[i][j];
            printf("%d ", loc_3[i][j]);
        }
    }

    return *loc_3;
}