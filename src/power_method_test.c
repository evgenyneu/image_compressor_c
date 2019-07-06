#include "external/minunit.h"
#include "linear_algebra.h"
#include "power_method.h"
#include "power_method_test.h"

static char *test_dominant_eigen_system()
{
    double matrix_data[] = {
                                7, -2, 0,
                                -2, 6, -2,
                                0, -2, 5
                            };

    Matrix *matrix = new_matrix_from_array(matrix_data, 3, 3);

    double eigenvalue;
    Matrix *result = dominant_eigen_system(matrix, 4, &eigenvalue);

    MU_APPROX_DOUBLE(eigenvalue, 8.887124, 0.00001);
    MU_EQUAL_INT(result->row_num, 3);
    MU_EQUAL_INT(result->col_num, 1);

    // Free memory
    free_matrix(matrix);
    matrix = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}


static char *test_dominant_eigen_system_zero_eigenvalue()
{
    double matrix_data[] = {
                                0, 0,
                                0, 0
                            };

    Matrix *matrix = new_matrix_from_array(matrix_data, 2, 2);

    double eigenvalue;
    Matrix *result = dominant_eigen_system(matrix, 4, &eigenvalue);

    MU_ASSERT(result == NULL);
    MU_EQUAL_DOUBLE(eigenvalue, 0.0);

    // Free memory
    free_matrix(matrix);
    matrix = NULL;

    return 0;
}

char *load_all_power_method_tests(void)
{
    MU_RUN_TEST(test_dominant_eigen_system);
    MU_RUN_TEST(test_dominant_eigen_system_zero_eigenvalue);
    return 0;
}