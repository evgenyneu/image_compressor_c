#include "external/minunit.h"
#include "linear_algebra_test.h"

static char * test_multiply_matrices()
{
    return 0;
}

char * load_all_linear_algebra_tests(void)
{
    mu_run_test(test_multiply_matrices);
    return 0;
}