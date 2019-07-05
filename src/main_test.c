#include <stdio.h>
#include "external/minunit.h"
#include "load_image_test.h"

int tests_run = 0;

static char * all_tests()
{
    mu_run_test(load_all_image_tests);
    return 0;
}

int main(void)
{
    char *result = all_tests();
    printf("Tests run: %d\n", tests_run);

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