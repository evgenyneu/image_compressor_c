#include <stdio.h>
#include <stdlib.h>
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

    for (iteration = 0; iteration < max_eigenvalues; iteration++)
    {
        Matrix *matrix_gramian = gramian(matrix);

        double eigenvalue;
        Matrix *v = dominant_eigen_system(matrix_gramian, iterations, &eigenvalue);

        if (eigenvalue == 0)
        {
            break;
        }

        // singular_value = math.sqrt(eigenvalue)
        // u = find_u_from_v(matrix, v=v, singular_value=singular_value)
        // svd_items.append((u, singular_value, v))

        // if iteration == (max_eigenvalues - 1):
        //     break

        // # Calculate the first dominant term of the singular value expansion
        // dominant = u @ np.transpose(v) * singular_value

        // # Subtract the dominant term
        // matrix = matrix - dominant
    }

    // Free memeory
    free(u_vectors);
    u_vectors = NULL;

    free(singular_values);
    singular_values = NULL;

    free(v_vectors);
    v_vectors = NULL;

    return result;
}