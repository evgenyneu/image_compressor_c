#include "external/minunit.h"
#include "linear_algebra.h"
#include "linear_algebra_test.h"


static char * test_multiply_matrix_with_a_number()
{
    double matrix1_data[] = {
                                1, 2,
                                3, 4,
                                5, 6
                            };

    Matrix *matrix1 = new_matrix_from_array(matrix1_data, 3, 2);

    Matrix *result = multiply_matrix_with_a_number(matrix1, 3);

    MU_EQUAL_INT(result->row_num, 3);
    MU_EQUAL_INT(result->col_num, 2);

    MU_EQUAL_DOUBLE(result->data[0], 3.0);
    MU_EQUAL_DOUBLE(result->data[1], 6.0);
    MU_EQUAL_DOUBLE(result->data[2], 9.0);
    MU_EQUAL_DOUBLE(result->data[3], 12.0);
    MU_EQUAL_DOUBLE(result->data[4], 15.0);
    MU_EQUAL_DOUBLE(result->data[5], 18.0);


    // Free memory
    free_matrix(matrix1);
    matrix1 = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}


static char * test_multiply_matrices()
{
    double matrix1_data[] = {
                                1, 2,
                                3, 4,
                                5, 6
                            };

    Matrix *matrix1 = new_matrix_from_array(matrix1_data, 3, 2);

    double matrix2_data[] = {
                                4, 1, -7,
                                1, 0,  2
                            };

    Matrix *matrix2 = new_matrix_from_array(matrix2_data, 2, 3);

    Matrix *result = multiply_matrices(matrix1, matrix2);

    MU_EQUAL_INT(result->row_num, 3);
    MU_EQUAL_INT(result->col_num, 3);

    MU_EQUAL_DOUBLE(result->data[0], 6.0);
    MU_EQUAL_DOUBLE(result->data[1], 1.0);
    MU_EQUAL_DOUBLE(result->data[2], -3.0);

    MU_EQUAL_DOUBLE(result->data[3], 16.0);
    MU_EQUAL_DOUBLE(result->data[4], 3.0);
    MU_EQUAL_DOUBLE(result->data[5], -13.0);

    MU_EQUAL_DOUBLE(result->data[6], 26.0);
    MU_EQUAL_DOUBLE(result->data[7], 5.0);
    MU_EQUAL_DOUBLE(result->data[8], -23.0);

    // Free memory
    free_matrix(matrix1);
    matrix1 = NULL;

    free_matrix(matrix2);
    matrix2 = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}


static char * test_add_matrices()
{
    double matrix1_data[] = {
                                1, 2,
                                3, 4,
                                5, 6
                            };

    Matrix *matrix1 = new_matrix_from_array(matrix1_data, 3, 2);

    double matrix2_data[] = {
                                4, 1,
                                1, 0,
                                1, -3
                            };

    Matrix *matrix2 = new_matrix_from_array(matrix2_data, 3, 2);

    Matrix *result = add_matrices(matrix1, matrix2);

    MU_EQUAL_INT(result->row_num, 3);
    MU_EQUAL_INT(result->col_num, 2);

    MU_EQUAL_DOUBLE(result->data[0], 5.0);
    MU_EQUAL_DOUBLE(result->data[1], 3.0);
    MU_EQUAL_DOUBLE(result->data[2], 4.0);
    MU_EQUAL_DOUBLE(result->data[3], 4.0);
    MU_EQUAL_DOUBLE(result->data[4], 6.0);
    MU_EQUAL_DOUBLE(result->data[5], 3.0);

    // Free memory
    free_matrix(matrix1);
    matrix1 = NULL;

    free_matrix(matrix2);
    matrix2 = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}

static char *test_new_matrix_from_array()
{
    double array[] = {
                        1, 2,
                        3, 4,
                        5, 6
                     };

    Matrix *matrix = new_matrix_from_array(array, 3, 2);
    MU_EQUAL_INT(matrix->row_num, 3);
    MU_EQUAL_INT(matrix->col_num, 2);
    MU_EQUAL_DOUBLE(matrix->data[0], 1.0);
    MU_EQUAL_DOUBLE(matrix->data[1], 2.0);
    MU_EQUAL_DOUBLE(matrix->data[2], 3.0);
    MU_EQUAL_DOUBLE(matrix->data[5], 6.0);

    free_matrix(matrix);
    matrix = NULL;

    return 0;
}

static char *test_new_matrix()
{
    Matrix *matrix = new_matrix(2, 3);
    MU_ASSERT(matrix->data != NULL);
    MU_EQUAL_INT(matrix->row_num, 2);
    MU_EQUAL_INT(matrix->col_num, 3);

    free_matrix(matrix);
    matrix = NULL;

    return 0;
}

char * load_all_linear_algebra_tests(void)
{
    MU_RUN_TEST(test_new_matrix);
    MU_RUN_TEST(test_new_matrix_from_array);
    MU_RUN_TEST(test_add_matrices);
    MU_RUN_TEST(test_multiply_matrices);
    MU_RUN_TEST(test_multiply_matrix_with_a_number);
    return 0;
}