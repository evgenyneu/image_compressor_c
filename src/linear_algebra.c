#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linear_algebra.h"

Matrix *new_matrix(int row_num, int col_num)
{
    Matrix *matrix = malloc(sizeof(Matrix));
    if (matrix == NULL) return NULL;
    matrix->data = malloc((unsigned long) (row_num * col_num) * sizeof(double));

    if (matrix->data == NULL)
    {
        perror("Error allocating memory for a matrix");
        exit(EXIT_FAILURE);
    }

    matrix->row_num = row_num;
    matrix->col_num = col_num;

    return matrix;
}

Matrix *new_matrix_from_array(double *array, int row_num, int col_num)
{
   Matrix *matrix = new_matrix(row_num, col_num);
   memcpy(matrix->data, array, (unsigned long)(row_num * col_num) * sizeof(double));
   return matrix;
}

void free_matrix(Matrix *matrix)
{
    free(matrix->data);
    free(matrix);
}

Matrix *add_matrices(Matrix *matrix1, Matrix *matrix2)
{
    if (matrix1->row_num != matrix2->row_num ||
        matrix1->col_num != matrix2->col_num)
    {
        perror("Dimensions of the two matrices do not match");
        exit(EXIT_FAILURE);
    }

    Matrix *result_matrix = new_matrix(matrix1->row_num, matrix1->col_num);

    int i_row, i_col, index;

    for (i_row = 0; i_row < matrix1->row_num; i_row++)
    {
        for (i_col = 0; i_col < matrix1->col_num; i_col++)
        {
            index = i_row * matrix2->col_num + i_col;
            result_matrix->data[index] = matrix1->data[index] + matrix2->data[index];
        }
    }

    return result_matrix;
}


Matrix *multiply_matrices(Matrix *matrix1, Matrix *matrix2)
{
    if (matrix1->col_num != matrix2->row_num)
    {
        perror("Incompatible matrix dimensions");
        exit(EXIT_FAILURE);
    }

    Matrix *product = new_matrix(matrix1->row_num, matrix2->col_num);

    int i, j, k, sum;

    for (i = 0; i < matrix1->row_num; i++)
    {
        for (j = 0; j < matrix2->col_num; j++)
        {
            sum = 0;

            for (k = 0; k < matrix1->col_num; k++)
            {
                sum += matrix1->data[i * matrix1->col_num + k]
                            * matrix2->data[k * matrix2->col_num + j];
            }

            product->data[i * matrix2->col_num + j] = sum;
        }
    }

    return product;
}

Matrix *multiply_matrix_with_a_number(Matrix *matrix, double number)
{
   Matrix *product = new_matrix(matrix->row_num, matrix->col_num);

   int i, j, index;

    for (i = 0; i < matrix->row_num; i++)
    {
        for (j = 0; j < matrix->col_num; j++)
        {
            index = i * matrix->col_num + j;
            product->data[index] = number * matrix->data[index];
        }
    }

    return product;
}
