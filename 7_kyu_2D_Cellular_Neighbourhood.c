/*
Task
        Given a neighbourhood type ("moore" or "von_neumann"), a 2D matrix (a list of lists) and a pair of coordinates, return the list of neighbours of the given cell.

Notes:

The order of the elements in the output list is not important
If the input indexes are outside the matrix, return an empty list
        If the the matrix is empty, return an empty list
        Order of the indices: the first index should be applied for the outer/first matrix layer and the last index for the most inner/last layer. coordinates = (m, n) should be applied like mat[m][n]
Examples
\ n   0    1    2    3    4
m  --------------------------
0  |  0 |  1 |  2 |  3 |  4 |
1  |  5 |  6 |  7 |  8 |  9 |
2  | 10 | 11 | 12 | 13 | 14 |
3  | 15 | 16 | 17 | 18 | 19 |
4  | 20 | 21 | 22 | 23 | 24 |
--------------------------

get_neighborhood("moore", mat, (1,1)) == [0, 1, 2, 5, 7, 10, 11, 12]
get_neighborhood("moore", mat, (0,0)) == [1, 6, 5]
get_neighborhood("moore", mat, (4,2)) == [21, 16, 17, 18, 23]
get_neighborhood("von_neumann", mat, (1,1)) == [1, 5, 7, 11]
get_neighborhood("von_neumann", mat, (0,0)) == [1, 5]
get_neighborhood("von_neumann", mat, (4,2)) == [21, 17, 23]*/

#include <stdlib.h>

enum neighbourhood_type { MOORE, VON_NEUMANN };
struct coordinates { int row, col; };

int get_neighbourhood(
        enum neighbourhood_type type,
        int rows, int cols,
        const int matrix[rows][cols],
        struct coordinates cell,
        int neighbours[]) {

    int cnt = 0;
    if(cell.row < 0 || cell.row >= rows || cell.col < 0 || cell.col >= cols) {
        return 0;
    }
    int s[8][2] = {{0, -1}, {0, 1}, {-1, 0},
                       {1, 0}, {-1, -1}, {-1, 1},
                       {1, -1}, {1, 1}};
    int s_cnt = (type == VON_NEUMANN) ? 4 : 8;
    for(int i = 0; i < s_cnt; i++) {
        int newY = cell.row + s[i][0];
        int newX = cell.col + s[i][1];
        if(newY >= 0 && newY < rows && newX >= 0 && newX < cols && matrix[newY][newX] != -1) {
            neighbours[cnt++] = matrix[newY][newX];
        }
    }

    return cnt;
}