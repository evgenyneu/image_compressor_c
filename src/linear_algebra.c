#include <stdio.h>
#include <stdlib.h>
#include "linear_algebra.h"

Matrix *new_matrix(int row_num, int col_num)
{
    Matrix *matrix = malloc(sizeof(Matrix));
    if (matrix == NULL) return NULL;
    matrix->data = malloc((unsigned long) (row_num * col_num) * sizeof(double));
    matrix->row_num = row_num;
    matrix->col_num = col_num;

    return matrix;
}

void free_matrix(Matrix *matrix)
{
    free(matrix->data);
    free(matrix);
}