#include <munistd.h>
#include "external/minunit.h"
#include "core.h"


static char *test_run_benchmark()
{
    const char *output_path = "images/marmite_output_500x500.jpg";

    if (access(output_path, F_OK) != -1)
    {
        if (remove(output_path) != 0)
        {
            printf("Unable to delete the file");
        }
    }

    MU_ASSERT(access(output_path, F_OK) == -1);

    compress_image_file("images/marmite_500x500.jpg", output_path, 30, 5);

    // Check image exists
    MU_ASSERT(access(output_path, F_OK) != -1);

    // Delete test file
    if (remove(output_path) != 0)
    {
        printf("Unable to delete the file");
    }

    return 0;
}


char *load_all_benchmark_tests(void)
{
    MU_RUN_TEST(test_run_benchmark);
    return 0;
}