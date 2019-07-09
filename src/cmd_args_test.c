#include "external/minunit.h"
#include "cmd_args_test.h"
#include "cmd_args.h"

static char *test_parse_cmd_args_all()
{
    const char *argv[] = { "compressor", "--terms=13", "--iterations=3", "image_path", "output_path" };
    int argc = sizeof(argv) / sizeof(char *);
    CmdArgs *cmd_args = new_cmd_args();

    char *result = parse_cmd_args(argc, (char *const *) argv, cmd_args);

    printf("Result:\n%s", result);

    // Free memory
    free_cmd_args(cmd_args);
    free(result);

    return 0;
}

char *load_all_cmd_args_tests(void)
{
    MU_RUN_TEST(test_parse_cmd_args_all);
    return 0;
}