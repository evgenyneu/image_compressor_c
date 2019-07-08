#include "external/minunit.h"
#include "cmd_args_test.h"
#include "cmd_args.h"

static char *test_parse_cmd_args()
{
    const char *argv[] = { "compressor", "--terms=13", "--iterations=3", "image_path", "output_path" };

    int result = parse_cmd_args(sizeof(argv), argv);

    return 0;
}

char *load_all_cmd_args_tests(void)
{
    MU_RUN_TEST(test_parse_cmd_args);
    return 0;
}