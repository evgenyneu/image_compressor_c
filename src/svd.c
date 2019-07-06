#include <stdio.h>
#include <stdlib.h>
#include "svd.h"

Matrix *find_u_from_v(Matrix *matrix, Matrix *v, double singular_value)
{
    Matrix *product = multiply_matrices(matrix, v);
    Matrix *vector_u = multiply_matrix_with_a_number(product, 1 / singular_value);

    free_matrix(product);
    product = NULL;

    return vector_u;
}

SVD *svd(Matrix *matrix, int max_eigenvalues, int iterations)
{
    SVD *result = malloc(sizeof(SVD));

    printf("size of SVF %lu", sizeof(SVD));

    if (result == NULL)
    {
        perror("Error allocating memory for SVD");
        exit(EXIT_FAILURE);
    }

    return result;
}