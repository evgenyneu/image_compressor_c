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


static char *test_svd()
{
    double matrix_data[] = {
                                1.3, -8,
                                -4, 1.5,
                                2, -3.1
                           };

    Matrix *matrix = new_matrix_from_array(matrix_data, 3, 2);

    SVD *result = svd(matrix, 2, 100);

    MU_EQUAL_INT(result->elements, 2);

    // Check first SVD elements
    // -----------

    Matrix *u = result->u_vectors[0];
    MU_EQUAL_INT(u->row_num, 3);
    MU_EQUAL_INT(u->col_num, 1);
    MU_APPROX_DOUBLE(u->data[0], 0.868709913531374, 1e-12);
    MU_APPROX_DOUBLE(u->data[1], -0.302483627893818, 1e-12);
    MU_APPROX_DOUBLE(u->data[2], 0.392233018738233, 1e-12);

    MU_APPROX_DOUBLE(result->singular_values[0], 9.16790313574705, 1e-12);

    Matrix *v = result->v_vectors[0];
    MU_EQUAL_INT(v->row_num, 2);
    MU_EQUAL_INT(v->col_num, 1);
    MU_APPROX_DOUBLE(v->data[0], 0.34072387004860993, 1e-12);
    MU_APPROX_DOUBLE(v->data[1], -0.9401634136569548, 1e-12);


    // Check second SVD elements
    // -----------

    u = result->u_vectors[1];
    MU_EQUAL_INT(u->row_num, 3);
    MU_EQUAL_INT(u->col_num, 1);
    MU_APPROX_DOUBLE(u->data[0], -0.409229029771402, 1e-12);
    MU_APPROX_DOUBLE(u->data[1], -0.884435018345001, 1e-12);
    MU_APPROX_DOUBLE(u->data[2], 0.22429065856034883, 1e-12);

    MU_APPROX_DOUBLE(result->singular_values[1], 3.6741736613229743, 1e-12);

    v = result->v_vectors[1];
    MU_EQUAL_INT(v->row_num, 2);
    MU_EQUAL_INT(v->col_num, 1);
    MU_APPROX_DOUBLE(v->data[0], 0.9401634136569545, 1e-12);
    MU_APPROX_DOUBLE(v->data[1], 0.34072387004861016, 1e-12);

    // Free memory
    // -------------

    free_matrix(matrix);
    matrix = NULL;

    free_svd(result);
    result = NULL;

    return 0;
}


static char *test_svd_with_zero_singular_values()
{
    double matrix_data[] = {
                                3, -2,
                                -3, 2
                           };

    Matrix *matrix = new_matrix_from_array(matrix_data, 2, 2);

    SVD *result = svd(matrix, 2, 10);

    MU_EQUAL_INT(result->elements, 1);

    // Check first SVD elements
    // -----------

    Matrix *u = result->u_vectors[0];
    MU_EQUAL_INT(u->row_num, 2);
    MU_EQUAL_INT(u->col_num, 1);
    MU_APPROX_DOUBLE(u->data[0], 0.70710678118655, 1e-12);
    MU_APPROX_DOUBLE(u->data[1], -0.70710678118655, 1e-12);

    MU_APPROX_DOUBLE(result->singular_values[0], 5.09901951359278, 1e-12);

    Matrix *v = result->v_vectors[0];
    MU_EQUAL_INT(v->row_num, 2);
    MU_EQUAL_INT(v->col_num, 1);
    MU_APPROX_DOUBLE(v->data[0], 0.83205029433784, 1e-12);
    MU_APPROX_DOUBLE(v->data[1], -0.55470019622523, 1e-12);


    // Free memory
    // -------------

    free_matrix(matrix);
    matrix = NULL;

    free_svd(result);
    result = NULL;

    return 0;
}


char *load_all_svd_tests(void)
{
    MU_RUN_TEST(test_find_u_from_v);
    MU_RUN_TEST(test_svd);
    MU_RUN_TEST(test_svd_with_zero_singular_values);
    return 0;
}