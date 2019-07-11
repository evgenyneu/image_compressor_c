#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "core.h"
#include "svd.h"
#include "load_image.h"

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

void compress_image_file(const char *path, const char *output, int terms, int iterations)
{
    int matrix_num = 0;
    Matrix **matrices = load_image(path, &matrix_num);

    Matrix **matrices_compressed = compress_image(matrices, terms, iterations, matrix_num);

    save_image(output, matrices_compressed, matrix_num);

    // Free memory
    // ---------

    int i;

    for (i = 0; i < matrix_num; i++)
    {
        free_matrix(matrices[i]);
        free_matrix(matrices_compressed[i]);
    }

    free(matrices);
    matrices = NULL;
    free(matrices_compressed);
    matrices_compressed = NULL;
}


void compress_from_command_line_options(CmdArgs *cmd_args, int silent)
{
    clock_t start_clock = clock();


    if (silent == 0)
    {
        printf("\nCompressing %s to %s\n", cmd_args->path, cmd_args->output);
        printf("Terms: %d\n", cmd_args->terms);
        printf("Iterations: %d\n", cmd_args->iterations);
    }

    compress_image_file(cmd_args->path, cmd_args->output, cmd_args->terms, cmd_args->iterations);

    clock_t end_clock = clock();
    double time_spent_sec = (double)(end_clock - start_clock) / CLOCKS_PER_SEC;

    if (silent == 0)
    {
        printf("Done\n");
    }

    if (cmd_args->benchmark && silent == 0)
    {
        printf("Compression time: %f s\n", time_spent_sec);
    }
}