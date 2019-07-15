#include <stdio.h>
#include "external/minunit.h"
#include "load_image_test.h"
#include "linear_algebra_test.h"
#include "power_method_test.h"
#include "svd_test.h"
#include "core_test.h"
#include "string_util_test.h"
#include "cmd_args_test.h"
#include "benchmark_test.h"
#include "annotate_test.h"

int tests_run = 0;

static char *all_tests()
{
    MU_RUN_TEST(load_all_image_tests);
    MU_RUN_TEST(load_all_linear_algebra_tests);
    MU_RUN_TEST(load_all_power_method_tests);
    MU_RUN_TEST(load_all_svd_tests);
    MU_RUN_TEST(load_all_core_tests);
    MU_RUN_TEST(load_all_string_util_tests);
    MU_RUN_TEST(load_all_cmd_args_tests);
    MU_RUN_TEST(load_all_benchmark_tests);
    MU_RUN_TEST(load_all_annotate_tests);
    return 0;
}

int main(void)
{
    printf("\nRunning tests:\n");
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