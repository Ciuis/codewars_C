/*
Create a function that returns the CSV representation of a two-dimensional numeric array.

Example:

input:
[[ 0, 1, 2, 3, 4 ],
[ 10,11,12,13,14 ],
[ 20,21,22,23,24 ],
[ 30,31,32,33,34 ]]

output:
'0,1,2,3,4\n'
+'10,11,12,13,14\n'
+'20,21,22,23,24\n'
+'30,31,32,33,34'

Array's length > 2.*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *to_csv_text(size_t rows, size_t cols, const int matrix[rows][cols]);

int main(void) {
    size_t rows = 4;
    size_t cols = 5;
    int mat1[4][5] = {
            {0, 1, 2, 3, 45},
            {10, 11, 12, 13, 14},
            {20, 21, 22, 23, 24},
            {30, 31, 32, 33, 34}
    };

    printf("%s", to_csv_text(rows, cols, mat1));

}


char *to_csv_text(size_t rows, size_t cols, const int matrix[rows][cols]) {
    char* csv = (char*)malloc(cols * rows * 2 * sizeof(int));

    int idx = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            idx += snprintf(NULL, 0, "%d", matrix[i][j]);
            idx += (i == rows - 1 && j == cols - 1) ? 0 : (j == cols - 1) ? 1 : 2;;
        }
    }

    int pos = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            pos += sprintf(csv + pos, "%d", matrix[i][j]);
            pos += sprintf(csv + pos, "%s", (i == rows - 1 && j == cols - 1) ? "" : (j == cols - 1) ? "\n" : ",");
        }
    }

    return csv;
}


/*
char *to_csv_text(size_t rows, size_t cols, const int matrix[rows][cols]) {
    char *output = calloc(rows * cols * 10, sizeof(char));
    for (size_t i = 0; i < rows; i++) {
        sprintf(output, "%s%d", output, matrix[i][0]);
        for (size_t j = 1; j < cols; j++) {
            sprintf(output, "%s,%d", output, matrix[i][j]);
        }
        if (i < rows - 1) {
            sprintf(output, "%s\n", output);
        }
    }
    return output;
}*/


/*char *to_csv_text(size_t rows, size_t cols, const int matrix[rows][cols])
{
    char *result = calloc(12 * rows * cols, sizeof(char));
    char *ptr = result;

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            ptr += sprintf(ptr, "%d,", matrix[i][j]);
        }

        *(ptr - 1) = '\n';
    }

    *(ptr - 1) = '\0';

    return result;
}*/
