#include "external/minunit.h"
#include "benchmark_test.h"
#include <time.h>
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


// static char *test_run_benchmark()
// {
//     CmdArgs *cmd_args = new_cmd_args();
//     benchmark_options(cmd_args);
//     // cmd_args->path = copy_string("images/marmite_1000x1000.jpg");

//     compress_from_command_line_options(cmd_args, 0);

//     return 0;
// }


char *load_all_benchmark_tests(void)
{
    // MU_RUN_TEST(test_run_benchmark);
    MU_RUN_TEST(test_matrix_multiplication);
    return 0;
}