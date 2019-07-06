#include <stdio.h>
#include <string.h>
#include "power_method.h"

Matrix *dominant_eigen_system(Matrix *matrix, int iterations, double *eigenvalue)
{
    // Create an initial unit vector
    double unit_vector_array[matrix->col_num];
    memset(unit_vector_array, 0, (unsigned long) matrix->col_num * sizeof(double));
    unit_vector_array[0] = 1;
    Matrix *unit_vector = new_matrix_from_array(unit_vector_array, matrix->col_num, 1);

    int i;
    Matrix *product;
    double vec_length;

    for (i = 0; i < iterations; i++)
    {
        product = multiply_matrices(matrix, unit_vector);
        vec_length = norm(product);

        free_matrix(unit_vector);
        unit_vector = NULL;

        // Reached zero eigenvalue
        if (vec_length < ALMOST_ZERO)
        {
            free_matrix(product);
            product = NULL;

            *eigenvalue = 0;
            return NULL;
        }

        // Normalize unit vector
        unit_vector = multiply_matrix_with_a_number(product, 1 / vec_length);
        free_matrix(product);
        product = NULL;
    }

    // Calculate dominant eigenvalue
    product = multiply_matrices(matrix, unit_vector);
    *eigenvalue = dot_product(product, unit_vector);

    // Free memory
    free_matrix(product);
    product = NULL;

    return unit_vector;
}