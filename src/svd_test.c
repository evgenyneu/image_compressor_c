#include "external/minunit.h"
#include "svd_test.h"
#include "linear_algebra.h"
#include "svd.h"

static char *test_find_u_from_v()
{
    double matrix_data[] = {
                                3, -2,
                                -3, 2
                           };

    Matrix *matrix = new_matrix_from_array(matrix_data, 2, 2);

    double eigenvalue = 25.999999999999996;
    double singular_value = sqrt(eigenvalue);

    double eigenvector_data[] = {
                                    0.8320502943378436,
                                    -0.5547001962252291
                                };

    Matrix *eigenvector = new_matrix_from_array(eigenvector_data, 2, 1);

    Matrix *result = find_u_from_v(matrix, eigenvector, singular_value);

    MU_EQUAL_INT(result->row_num, 2);
    MU_EQUAL_INT(result->col_num, 1);

    MU_APPROX_DOUBLE(result->data[0], 0.707106, 0.00001);
    MU_APPROX_DOUBLE(result->data[1], -0.707106, 0.00001);

    // Free memory
    free_matrix(matrix);
    matrix = NULL;

    // Free memory
    free_matrix(eigenvector);
    eigenvector = NULL;

    free_matrix(result);
    result = NULL;

    return 0;
}

char *load_all_svd_tests(void)
{
    MU_RUN_TEST(test_find_u_from_v);
    return 0;
}