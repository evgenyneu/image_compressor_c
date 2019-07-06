#include <stdio.h>
#include "external/minunit.h"
#include "load_image_test.h"
#include "linear_algebra_test.h"
#include "power_method_test.h"
#include "svd_test.h"

int tests_run = 0;

static char *all_tests()
{
    MU_RUN_TEST(load_all_image_tests);
    MU_RUN_TEST(load_all_linear_algebra_tests);
    MU_RUN_TEST(load_all_power_method_tests);
    MU_RUN_TEST(load_all_svd_tests);
    return 0;
}

int main(void)
{
    char *result = all_tests();
    printf("\nTests run: %d\n", tests_run);

    if (result != 0)
    {
        printf("%s\n", result);
    }
    else
    {
        printf("\nALL TESTS PASSED\n\n");
    }

    return result != 0;
}