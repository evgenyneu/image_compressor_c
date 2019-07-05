#include "external/minunit.h"
#include "linear_algebra.h"
#include "linear_algebra_test.h"


static char * test_multiply_matrices()
{
    // double **result = multiply_matrices(a, a_rownum, a_colnum, b, b_rownum, b_colnum);
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
    MU_RUN_TEST(test_multiply_matrices);
    MU_RUN_TEST(test_new_matrix);
    return 0;
}