#include <stdio.h>
#include "svd.h"

Matrix *find_u_from_v(Matrix *matrix, Matrix *v, double singular_value)
{
    Matrix *product = multiply_matrices(matrix, v);
    Matrix *vector_u = multiply_matrix_with_a_number(product, 1 / singular_value);

    free_matrix(product);
    product = NULL;

    return vector_u;
}