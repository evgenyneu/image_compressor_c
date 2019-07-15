#include <unistd.h>
#include "external/minunit.h"
#include "annotate_test.h"
#include "annotate.h"
#include "file_util.h"

static char *test_annotate()
{
    const char *output_path = "images/marmite_1000x1000_test.jpg";

    if (copy_file("images/marmite_1000x1000.jpg", output_path, 1) != 0)
    {
        printf("Unable to copy a file");
        MU_ASSERT(0);
    }

    MU_ASSERT(access(output_path, F_OK) != -1);

    annotate(output_path, 10, 1.5, 500);

    // Delete test file
    if (remove(output_path) != 0)
    {
        printf("Unable to delete the file");
    }

    return 0;
}

char *load_all_annotate_tests(void)
{
    MU_RUN_TEST(test_annotate);
    return 0;
}