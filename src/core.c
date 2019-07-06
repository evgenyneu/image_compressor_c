#include <stdio.h>
#include <stdlib.h>
#include "core.h"
#include "svd.h"

Matrix **compress_image(Matrix **matrices, int terms, int iterations, int channels)
{
    int i;
    Matrix **result = malloc((unsigned long) channels * sizeof(Matrix *));
    SVD *svd_data;
    Matrix *compressed;

    for(i = 0; i < channels; i++)
    {
        svd_data = svd(matrices[i], terms, iterations);

        if (svd_data->elements == 0)
        {
            // Could not calculate SVD (dominant eigenvalue was zero)
            free_svd(svd_data);
            svd_data = NULL;
            free(result);
            result = NULL;
            return NULL;
        }

        compressed = singular_value_expansion(svd_data);
        result[i] = compressed;

        free_svd(svd_data);
        svd_data = NULL;
    }

    return result;
}