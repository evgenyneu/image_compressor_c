#include "external/minunit.h"
#include "linear_algebra.h"
#include "linear_algebra_test.h"


static char *test_gramian()
{
    double matrix_data[] = {
                                3.912, -2.01, 6,
                                -2.99998, -1.23, 5.1,
                                -2.1, 3.5, 3.1,
                                -0.0001, 1.1, 1.1
                            };

    Matrix *matrix = new_matrix_from_array(matrix_data, 4, 3);

    Matrix *result = gramian(matrix);

    MU_EQUAL_INT(result->row_num, 3);
    MU_EQUAL_INT(result->col_num, 3);

    MU_APPROX_DOUBLE(result->data[0], 28.7136, 0.0001);
    MU_APPROX_DOUBLE(result->data[1], -11.5232546, 0.0001);
    MU_APPROX_DOUBLE(result->data[2], 1.661992, 0.0001);
    MU_APPROX_DOUBLE(result->data[4], 19.013, 0.0001);
    MU_APPROX_DOUBLE(result->data[5], -6.27299, 0.0001);
    MU_APPROX_DOUBLE(result->data[8], 72.83, 0.0001);

    // Free memory
    free_matrix(matrix);
    matrix = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}


static char *test_norm()
{
    double matrix_data[] = {
                                1,
                                2,
                                3,
                            };

    Matrix *matrix = new_matrix_from_array(matrix_data, 3, 1);

    double result = norm(matrix);

    MU_APPROX_DOUBLE(result, 3.741657, 0.0001);

    // Free memory
    free_matrix(matrix);
    matrix = NULL;

    return 0;
}


static char *test_dot_product()
{
    double matrix_data1[] = {
                                1.3,
                                3.1,
                                5.7,
                            };

    Matrix *matrix1 = new_matrix_from_array(matrix_data1, 3, 1);

    double matrix_data2[] = {
                                0,
                                2.1,
                                1.97999,
                            };

    Matrix *matrix2 = new_matrix_from_array(matrix_data2, 3, 1);


    double result = dot_product(matrix1, matrix2);

    MU_APPROX_DOUBLE(result, 17.7959, 0.0001);

    // Free memory
    free_matrix(matrix1);
    matrix1 = NULL;

    free_matrix(matrix2);
    matrix2 = NULL;

    return 0;
}


static char *test_transpose()
{
    double matrix_data[] = {
                                1.9, 2,
                                3, 4,
                                5, 6
                            };

    Matrix *matrix = new_matrix_from_array(matrix_data, 3, 2);

    Matrix *result = transpose_matrix(matrix);

    MU_EQUAL_INT(result->row_num, 2);
    MU_EQUAL_INT(result->col_num, 3);

    MU_EQUAL_DOUBLE(result->data[0], 1.9);
    MU_EQUAL_DOUBLE(result->data[1], 3.0);
    MU_EQUAL_DOUBLE(result->data[2], 5.0);

    MU_EQUAL_DOUBLE(result->data[3], 2.0);
    MU_EQUAL_DOUBLE(result->data[4], 4.0);
    MU_EQUAL_DOUBLE(result->data[5], 6.0);


    // Free memory
    free_matrix(matrix);
    matrix = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}


static char *test_multiply_matrix_with_a_number()
{
    double matrix_data[] = {
                                1.1, 2,
                                4, 5,
                                5, 6
                            };

    Matrix *matrix = new_matrix_from_array(matrix_data, 3, 2);

    multiply_matrix_with_a_number(matrix, 2.98);

    MU_EQUAL_INT(matrix->row_num, 3);
    MU_EQUAL_INT(matrix->col_num, 2);

    MU_APPROX_DOUBLE(matrix->data[0], 3.278, 0.0001);
    MU_APPROX_DOUBLE(matrix->data[1], 5.96, 0.0001);
    MU_APPROX_DOUBLE(matrix->data[2], 11.92, 0.0001);;
    MU_APPROX_DOUBLE(matrix->data[3], 14.9, 0.0001);;
    MU_APPROX_DOUBLE(matrix->data[4], 14.9, 0.0001);;
    MU_APPROX_DOUBLE(matrix->data[5], 17.88, 0.0001);;


    // Free memory
    free_matrix(matrix);
    matrix = NULL;

    return 0;
}


static char *test_multiply_matrix_with_vector()
{
    double matrix1_data[] = {
                                1.1, 2.9, 2.5,
                                3, 4.3, 0,
                                5, 6, 9.1
                            };

    Matrix *matrix1 = new_matrix_from_array(matrix1_data, 3, 3);

    double matrix2_data[] = {
                                4.1,
                                1,
                                -2.1
                            };

    Matrix *matrix2 = new_matrix_from_array(matrix2_data, 3, 1);

    Matrix *result = multiply_matrix_with_vector(matrix1, matrix2, 2);

    MU_EQUAL_INT(result->row_num, 3);
    MU_EQUAL_INT(result->col_num, 1);

    MU_APPROX_DOUBLE(result->data[0], 4.32, 0.0001);
    MU_APPROX_DOUBLE(result->data[1], 33.2, 0.0001);
    MU_APPROX_DOUBLE(result->data[2], 14.78, 0.0001);

    // Free memory
    free_matrix(matrix1);
    matrix1 = NULL;

    free_matrix(matrix2);
    matrix2 = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}


static char *test_multiply_matrix_with_vector2()
{
    double matrix1_data[] = {
                                1.3, -8.0,
                                -4.0, 1.5,
                                2.0, -3.1
                            };

    Matrix *matrix1 = new_matrix_from_array(matrix1_data, 3, 2);

    double matrix2_data[] = {
                                0.340724,
                                -0.940163
                            };

    Matrix *matrix2 = new_matrix_from_array(matrix2_data, 2, 1);

    Matrix *result = multiply_matrix_with_vector(matrix1, matrix2, 1);

    MU_EQUAL_INT(result->row_num, 3);
    MU_EQUAL_INT(result->col_num, 1);

    MU_APPROX_DOUBLE(result->data[0], 7.96425, 0.0001);
    MU_APPROX_DOUBLE(result->data[1], -2.77314, 0.0001);
    MU_APPROX_DOUBLE(result->data[2], 3.59595, 0.0001);

    // Free memory
    free_matrix(matrix1);
    matrix1 = NULL;

    free_matrix(matrix2);
    matrix2 = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}


static char *test_multiply_vector_by_vector_transpose()
{
    double vector1_data[] = {
                                1.1,
                                3,
                                5
                            };

    Matrix *vector1 = new_matrix_from_array(vector1_data, 3, 1);

    double vector2_data[] = {
                                4.1,
                                1
                            };

    Matrix *vector2 = new_matrix_from_array(vector2_data, 2, 1);

    double matrix_data[] = {
                                1.0, 1.1,
                                1.2, 1.3,
                                1.4, 1.5
                            };

    Matrix *matrix = new_matrix_from_array(matrix_data, 3, 2);

    multiply_vector_by_vector_transpose(vector1, vector2, 2, matrix);

    MU_APPROX_DOUBLE(matrix->data[0], 10.02, 0.0001);
    MU_APPROX_DOUBLE(matrix->data[1], 3.3, 0.0001);

    MU_APPROX_DOUBLE(matrix->data[2], 25.8, 0.0001);
    MU_APPROX_DOUBLE(matrix->data[3], 7.3, 0.0001);

    MU_APPROX_DOUBLE(matrix->data[4], 42.4, 0.0001);
    MU_APPROX_DOUBLE(matrix->data[5], 11.5, 0.0001);

    // Free memory
    free_matrix(vector1);
    vector1 = NULL;

    free_matrix(vector2);
    vector2 = NULL;

    free_matrix(matrix);
    matrix = NULL;

    return 0;
}



static char *test_multiply_upper_symmetric_matrix_with_vector()
{
    double matrix1_data[] = {
                                1.3, -8.0, 2.1,
                                -8.0, 1.5, 3.1,
                                2.1,  3.1, -0.01
                            };

    Matrix *matrix1 = new_matrix_from_array(matrix1_data, 3, 3);

    double matrix2_data[] = {
                                0.340724,
                                -0.940163,
                                0.1,
                            };

    Matrix *matrix2 = new_matrix_from_array(matrix2_data, 3, 1);

    Matrix *result = multiply_upper_symmetric_matrix_with_vector(matrix1, matrix2);

    MU_EQUAL_INT(result->row_num, 3);
    MU_EQUAL_INT(result->col_num, 1);

    MU_APPROX_DOUBLE(result->data[0], 8.17425, 0.0001);
    MU_APPROX_DOUBLE(result->data[1], -3.82604, 0.0001);
    MU_APPROX_DOUBLE(result->data[2], -2.19998, 0.0001);

    // Free memory
    free_matrix(matrix1);
    matrix1 = NULL;

    free_matrix(matrix2);
    matrix2 = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}


static char *test_multiply_matrices()
{
    double matrix1_data[] = {
                                1.1, 2.9,
                                3, 4.3,
                                5, 6
                            };

    Matrix *matrix1 = new_matrix_from_array(matrix1_data, 3, 2);

    double matrix2_data[] = {
                                4.1, 1.99, -7,
                                1, 0.00001,  2
                            };

    Matrix *matrix2 = new_matrix_from_array(matrix2_data, 2, 3);

    Matrix *result = multiply_matrices(matrix1, matrix2);

    MU_EQUAL_INT(result->row_num, 3);
    MU_EQUAL_INT(result->col_num, 3);

    MU_APPROX_DOUBLE(result->data[0], 7.41, 0.0001);
    MU_APPROX_DOUBLE(result->data[1], 2.18903, 0.0001);;
    MU_APPROX_DOUBLE(result->data[2], -1.9, 0.0001);;

    MU_APPROX_DOUBLE(result->data[3], 16.6, 0.0001);;
    MU_APPROX_DOUBLE(result->data[4], 5.97004, 0.0001);;
    MU_APPROX_DOUBLE(result->data[5], -12.4, 0.0001);;

    MU_APPROX_DOUBLE(result->data[6], 26.5, 0.0001);;
    MU_APPROX_DOUBLE(result->data[7], 9.95006, 0.0001);;
    MU_APPROX_DOUBLE(result->data[8], -23.0, 0.0001);;

    // Free memory
    free_matrix(matrix1);
    matrix1 = NULL;

    free_matrix(matrix2);
    matrix2 = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}


static char *test_add_matrices()
{
    double matrix1_data[] = {
                                1.1, 2.0009,
                                3.4, 4.392,
                                5.3, 6.2
                            };

    Matrix *matrix1 = new_matrix_from_array(matrix1_data, 3, 2);

    double matrix2_data[] = {
                                4.43, 1,
                                1.32, 0.0001,
                                1.333, -3.7
                            };

    Matrix *matrix2 = new_matrix_from_array(matrix2_data, 3, 2);

    Matrix *result = add_matrices(matrix1, matrix2);

    MU_EQUAL_INT(result->row_num, 3);
    MU_EQUAL_INT(result->col_num, 2);

    MU_APPROX_DOUBLE(result->data[0], 5.53, 0.0001);
    MU_APPROX_DOUBLE(result->data[1], 3.0009, 0.0001);
    MU_APPROX_DOUBLE(result->data[2], 4.72, 0.0001);
    MU_APPROX_DOUBLE(result->data[3], 4.3921, 0.0001);
    MU_APPROX_DOUBLE(result->data[4], 6.633, 0.0001);
    MU_APPROX_DOUBLE(result->data[5], 2.5, 0.0001);

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
                        1.1, 2,
                        3, 4,
                        5, 6
                     };

    Matrix *matrix = new_matrix_from_array(array, 3, 2);
    MU_EQUAL_INT(matrix->row_num, 3);
    MU_EQUAL_INT(matrix->col_num, 2);
    MU_EQUAL_DOUBLE(matrix->data[0], 1.1);
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

char *load_all_linear_algebra_tests(void)
{
    MU_RUN_TEST(test_new_matrix);
    MU_RUN_TEST(test_new_matrix_from_array);
    MU_RUN_TEST(test_add_matrices);
    MU_RUN_TEST(test_multiply_matrices);
    MU_RUN_TEST(test_multiply_matrix_with_a_number);
    MU_RUN_TEST(test_transpose);
    MU_RUN_TEST(test_dot_product);
    MU_RUN_TEST(test_norm);
    MU_RUN_TEST(test_gramian);
    MU_RUN_TEST(test_multiply_matrix_with_vector);
    MU_RUN_TEST(test_multiply_matrix_with_vector2);
    MU_RUN_TEST(test_multiply_upper_symmetric_matrix_with_vector);
    MU_RUN_TEST(test_multiply_vector_by_vector_transpose);
    return 0;
}