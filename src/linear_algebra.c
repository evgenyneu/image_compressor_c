#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
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

    int i;
    int elements = matrix1->row_num * matrix1->col_num;

    for (i = 0; i < elements; i++)
    {
        result_matrix->data[i] = matrix1->data[i] + matrix2->data[i];
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

    int m = matrix1->row_num;
    int n = matrix2->col_num;
    int k = matrix1->col_num;

    // Use high-performace matrix multiplication from BLAS
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1,
        matrix1->data, k, matrix2->data, n, 0, product->data, n);

    return product;
}

Matrix *multiply_matrix_with_vector(Matrix *matrix, Matrix *vector)
{
    if (matrix->col_num != vector->row_num)
    {
        perror("Incompatible matrix dimensions");
        exit(EXIT_FAILURE);
    }

    if (vector->col_num != 1)
    {
        perror("Not a vector.");
        exit(EXIT_FAILURE);
    }

    Matrix *product = new_matrix(matrix->row_num, 1);

    int m = matrix->row_num;
    int n = matrix->col_num;

    cblas_dgemv(CblasRowMajor, CblasNoTrans, m, n, 1, matrix->data, n,
                vector->data, 1,  0, product->data, 1);

    return product;
}


Matrix *multiply_upper_symmetric_matrix_with_vector(Matrix *matrix, Matrix *vector)
{
    if (matrix->col_num != matrix->row_num)
    {
        perror("Matrix is not square");
        exit(EXIT_FAILURE);
    }

    if (matrix->col_num != vector->row_num)
    {
        perror("Incompatible matrix dimensions");
        exit(EXIT_FAILURE);
    }

    if (vector->col_num != 1)
    {
        perror("Not a vector.");
        exit(EXIT_FAILURE);
    }

    Matrix *product = new_matrix(matrix->row_num, 1);

    int n = matrix->col_num;

    cblas_dsymv(CblasRowMajor, CblasUpper, n, 1, matrix->data,
                n, vector->data, 1, 0, product->data, 1);

    return product;
}


void multiply_matrix_with_a_number(Matrix *matrix, double number)
{
    int i;
    int n = matrix->col_num;
    int row_num = matrix->row_num;

    for (i = 0; i < row_num; i++)
    {
        cblas_dscal(n, number, matrix->data + i * n, 1);
    }
}


Matrix *transpose_matrix(Matrix *matrix)
{
    Matrix *product = new_matrix(matrix->col_num, matrix->row_num);

    int i, j;

    for (i = 0; i < matrix->col_num; i++)
    {
        for (j = 0; j < matrix->row_num; j++)
        {
            product->data[i * matrix->row_num + j] = matrix->data[j * matrix->col_num + i];
        }
    }

    return product;
}


double dot_product(Matrix *matrix1, Matrix *matrix2)
{
    if (matrix1->row_num != matrix2->row_num ||
        matrix1->col_num != 1 || matrix2->col_num != 1)
    {
        perror("Matrices are not n by 1.");
        exit(EXIT_FAILURE);
    }

    int i;
    double result = 0;

    for (i = 0; i < matrix1->row_num; i++)
    {
        result += matrix1->data[i] * matrix2->data[i];
    }

    return result;
}


double norm(Matrix *matrix)
{
    return sqrt(dot_product(matrix, matrix));
}


Matrix *gramian(Matrix *matrix)
{
    Matrix *product = new_matrix(matrix->col_num, matrix->col_num);

    int n = matrix->col_num;
    int k = matrix->row_num;

    cblas_dsyrk(CblasRowMajor, CblasUpper, CblasTrans,
		 n, k, 1, matrix->data, n, 0, product->data, n);

    return product;
}
