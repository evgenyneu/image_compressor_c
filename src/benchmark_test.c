#include <time.h>
#include "external/minunit.h"
#include "benchmark_test.h"
#include "core.h"
#include "string_util.h"
#include "linear_algebra.h"


static char *test_matrix_multiplication()
{
    // Create two matrices
    int row_num = 1000;
    int col_num = 1000;

    double *matrix_data1 = malloc((unsigned long)(row_num * col_num) * sizeof(double));
    Matrix *matrix1 = new_matrix_from_array(matrix_data1, row_num, col_num);

    double *matrix_data2 = malloc((unsigned long)(row_num * col_num) * sizeof(double));
    Matrix *matrix2 = new_matrix_from_array(matrix_data2, row_num, col_num);


    // Fill matrices with random numbers between -max and max
    double max = 1000;
    int i, j;
    srand((unsigned int) time(NULL)); // randomize seed

    for (i=0; i<row_num; i++)
    {
        for(j=0; j<col_num; j++)
        {
            matrix_data1[i*col_num + j] = (double)rand() * 2 / RAND_MAX * max - max;
            matrix_data2[i*col_num + j] = (double)rand() * 2 / RAND_MAX * max - max;
        }
    }

    TICK(MULTIPLY_MATRICES);
    Matrix *result = multiply_matrices(matrix1, matrix2);
    TOCK(MULTIPLY_MATRICES);

    // Free memory
    free_matrix(result);
    result = NULL;

    free_matrix(matrix1);
    matrix1 = NULL;

    free_matrix(matrix2);
    matrix2 = NULL;

    return 0;
}


static char *test_benchmark_gramian()
{
    // Create a matrix
    int row_num = 1000;
    int col_num = 1200;

    double *matrix_data = malloc((unsigned long)(row_num * col_num) * sizeof(double));
    Matrix *matrix = new_matrix_from_array(matrix_data, row_num, col_num);

    // Fill matrix with random numbers between -max and max
    double max = 1000;
    int i, j;
    srand((unsigned int) time(NULL)); // randomize seed

    for (i=0; i<row_num; i++)
    {
        for(j=0; j<col_num; j++)
        {
            matrix_data[i*col_num + j] = (double)rand() * 2 / RAND_MAX * max - max;
        }
    }

    TICK(GRAMIAN);
    Matrix *result = gramian(matrix);
    TOCK(GRAMIAN);

    // Free memory
    free_matrix(result);
    result = NULL;

    free_matrix(matrix);
    matrix = NULL;

    return 0;
}

static char *test_benchmark_multiply_matrix_with_a_number()
{
    // Create a matrix
    int row_num = 5000;
    int col_num = 5000;

    double *matrix_data = malloc((unsigned long)(row_num * col_num) * sizeof(double));
    Matrix *matrix = new_matrix_from_array(matrix_data, row_num, col_num);

    // Fill matrix with random numbers between -max and max
    double max = 1000;
    int i, j;
    srand((unsigned int) time(NULL)); // randomize seed

    for (i=0; i<row_num; i++)
    {
        for(j=0; j<col_num; j++)
        {
            matrix_data[i*col_num + j] = (double)rand() * 2 / RAND_MAX * max - max;
        }
    }

    TICK(MULTIPLY_MATRIX_WITH_NUMBER);
    multiply_matrix_with_a_number(matrix, 2.98);
    TOCK(MULTIPLY_MATRIX_WITH_NUMBER);

    free_matrix(matrix);
    matrix = NULL;

    return 0;
}


char *load_all_benchmark_tests(void)
{
    MU_RUN_TEST(test_matrix_multiplication);
    MU_RUN_TEST(test_benchmark_gramian);
    MU_RUN_TEST(test_benchmark_multiply_matrix_with_a_number);
    return 0;
}