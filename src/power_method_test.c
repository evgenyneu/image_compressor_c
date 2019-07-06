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
    Matrix *result = dominant_eigen_system(matrix, 19, &eigenvalue);

    MU_EQUAL_INT(result->row_num, 3);
    MU_EQUAL_INT(result->col_num, 1);
    // MU_EQUAL_DOUBLE(eigenvalue, 0.0);

    // Free memory
    free_matrix(matrix);
    matrix = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}

char *load_all_power_method_tests(void)
{
    MU_RUN_TEST(test_dominant_eigen_system);
    return 0;
}