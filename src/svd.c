#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "svd.h"
#include "power_method.h"

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
    Matrix **u_vectors = malloc((unsigned long)max_eigenvalues * sizeof(Matrix *));
    double *singular_values = malloc((unsigned long)max_eigenvalues * sizeof(double));
    Matrix **v_vectors = malloc((unsigned long)max_eigenvalues * sizeof(Matrix *));

    if (result == NULL || u_vectors == NULL || singular_values == NULL || v_vectors == NULL)
    {
        perror("Error allocating memory for SVD");
        exit(EXIT_FAILURE);
    }

    int iteration;
    // Matrix used to find dominant eigenvalues 
    Matrix *current_matrix = new_matrix_from_array(matrix->data, matrix->row_num, matrix->col_num);

    for (iteration = 0; iteration < max_eigenvalues; iteration++)
    {
        Matrix *matrix_gramian = gramian(current_matrix);

        double eigenvalue;
        Matrix *v = dominant_eigen_system(matrix_gramian, iterations, &eigenvalue);

        if (eigenvalue == 0)
        {
            break;
        }

        double singular_value = sqrt(eigenvalue);
        Matrix *u = find_u_from_v(current_matrix, v, singular_value);
        
        // Store SVD elements
        u_vectors[iteration] = u;
        singular_values[iteration] = singular_value;
        v_vectors[iteration] = v;
        result->elements += 1;

        if (iteration == (max_eigenvalues - 1))
        {
            break;
        }

        // Calculate the first dominant term of the singular value expansion
        Matrix *v_transposed = transpose_matrix(v);
        Matrix *product_u_transpose = multiply_matrices(u, v_transposed);
        Matrix *dominant_matrix = multiply_matrix_with_a_number(product_u_transpose, -singular_value);

        // Subtract the dominant term
        Matrix *matrix_dominant_subtracted = add_matrices(current_matrix, dominant_matrix);

        // Use the new `current_matrix` for next iteration
        free_matrix(current_matrix);
        current_matrix = matrix_dominant_subtracted;

        // Free memory
        free_matrix(matrix_gramian);
        matrix_gramian = NULL;

        free_matrix(v_transposed);
        v_transposed = NULL;

        free_matrix(product_u_transpose);
        product_u_transpose = NULL;

        free_matrix(dominant_matrix);
        dominant_matrix = NULL;
    }

    // Copy SVD elements to `result`
    if (result->elements > 0)
    {
        result->u_vectors = malloc((unsigned long)(result->elements) * sizeof(Matrix *));
        result->singular_values = malloc((unsigned long)(result->elements) * sizeof(double));
        result->v_vectors = malloc((unsigned long)(result->elements) * sizeof(Matrix *));

        int i;
        for (i = 0; i < result->elements; i++)
        {
            result->u_vectors[i] = u_vectors[i];
            result->singular_values[i] = singular_values[i];
            result->v_vectors[i] = v_vectors[i];
        }
    }


    // Free memory
    free(u_vectors);
    u_vectors = NULL;

    free(singular_values);
    singular_values = NULL;

    free(v_vectors);
    v_vectors = NULL;

    free_matrix(current_matrix);
    current_matrix = NULL;

    return result;
}