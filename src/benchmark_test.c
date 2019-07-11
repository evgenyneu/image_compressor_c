#include "external/minunit.h"
#include "benchmark_test.h"
#include "core.h"
#include "string_util.h"


static char *test_run_benchmark()
{
    CmdArgs *cmd_args = new_cmd_args();
    benchmark_options(cmd_args);
    // cmd_args->path = copy_string("images/marmite_1000x1000.jpg");

    compress_from_command_line_options(cmd_args, 0);

    return 0;
}


char *load_all_benchmark_tests(void)
{
    // MU_RUN_TEST(test_run_benchmark);
    return 0;
}