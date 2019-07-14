#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "svd.h"
#include "power_method.h"

void free_svd(SVD *svd_data)
{
    int i;

    for (i = 0; i < svd_data->elements; i++)
    {
        free_matrix(svd_data->u_vectors[i]);
        free_matrix(svd_data->v_vectors[i]);
    }

    free(svd_data->u_vectors);
    svd_data->u_vectors = NULL;
    free(svd_data->singular_values);
    svd_data->singular_values = NULL;
    free(svd_data->v_vectors);
    svd_data->v_vectors = NULL;
    free(svd_data);
}

Matrix *find_u_from_v(Matrix *matrix, Matrix *v, double singular_value)
{
    Matrix *product = multiply_matrix_with_vector(matrix, v, 1 / singular_value);
    return product;
}

SVD *svd(Matrix *matrix, int max_eigenvalues, int iterations)
{
    SVD *result = malloc(sizeof(SVD));
    result->elements = 0;
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

        if (eigenvalue < ALMOST_ZERO)
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
        // and subtract is from current_matrix
        multiply_vector_by_vector_transpose(u, v, -singular_value, current_matrix);

        // Free memory
        free_matrix(matrix_gramian);
        matrix_gramian = NULL;
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


Matrix *singular_value_expansion(SVD *svd_data)
{
    if (svd_data->elements == 0)
    {
        return NULL;
    }

    Matrix *matrix = new_matrix(svd_data->u_vectors[0]->row_num, svd_data->v_vectors[0]->row_num);

    memset(matrix->data, 0, (unsigned long) (matrix->col_num * matrix->row_num) * sizeof(double));

    int i;
    Matrix *u_times_transpose_v;
    Matrix *transposed_v;
    Matrix *temp_matrix;

    for (i = 0; i < svd_data->elements; i++)
    {
        transposed_v = transpose_matrix(svd_data->v_vectors[i]);
        u_times_transpose_v = multiply_matrices(svd_data->u_vectors[i], transposed_v);
        multiply_matrix_with_a_number(u_times_transpose_v, svd_data->singular_values[i]);
        temp_matrix = add_matrices(matrix, u_times_transpose_v);

        free_matrix(matrix);
        matrix = temp_matrix;

        // Free memory

        free_matrix(transposed_v);
        transposed_v = NULL;

        free_matrix(u_times_transpose_v);
        u_times_transpose_v = NULL;
    }

    return matrix;
}