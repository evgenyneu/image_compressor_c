#include "external/minunit.h"
#include "cmd_args_test.h"
#include "cmd_args.h"


static char *test_parse_cmd_args__all_options_supplied()
{
    const char *argv[] = { "compressor", "--terms=13", "--iterations=3",
        "dir/image.jpg", "dir/compressed.jpg" };

    int argc = sizeof(argv) / sizeof(char *);
    CmdArgs *cmd_args = new_cmd_args();

    char *result = parse_cmd_args(argc, (char *const *) argv, cmd_args);

    MU_EQUAL_INT(cmd_args->ready_to_compress, 1);
    MU_EQUAL_INT(cmd_args->terms, 13);
    MU_EQUAL_INT(cmd_args->iterations, 3);
    MU_EQUAL_STR(cmd_args->path, "dir/image.jpg");
    MU_EQUAL_STR(cmd_args->output, "dir/compressed.jpg");

    // Free memory
    free_cmd_args(cmd_args);
    free(result);

    return 0;
}



char *load_all_cmd_args_tests(void)
{
    MU_RUN_TEST(test_parse_cmd_args__all_options_supplied);
    return 0;
}