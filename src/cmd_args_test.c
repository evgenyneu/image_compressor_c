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
    MU_EQUAL_INT(cmd_args->benchmark, 0);
    MU_EQUAL_INT(cmd_args->terms, 13);
    MU_EQUAL_INT(cmd_args->iterations, 3);
    MU_EQUAL_STR(cmd_args->path, "dir/image.jpg");
    MU_EQUAL_STR(cmd_args->output, "dir/compressed.jpg");
    MU_EQUAL_INT(cmd_args->show_annotation, 1);
    MU_EQUAL_STR(result, "");

    // Free memory
    free_cmd_args(cmd_args);
    free(result);

    return 0;
}

static char *test_parse_cmd_args__no_text()
{
    const char *argv[] = { "compressor", "--terms=13", "--iterations=3",
        "dir/image.jpg", "dir/compressed.jpg", "--notext"};

    int argc = sizeof(argv) / sizeof(char *);
    CmdArgs *cmd_args = new_cmd_args();

    char *result = parse_cmd_args(argc, (char *const *) argv, cmd_args);

    MU_EQUAL_INT(cmd_args->ready_to_compress, 1);
    MU_EQUAL_INT(cmd_args->show_annotation, 0);
    MU_EQUAL_STR(result, "");

    // Free memory
    free_cmd_args(cmd_args);
    free(result);

    return 0;
}


static char *test_parse_cmd_args__no_arguments()
{
    const char *argv[] = { "compressor"};

    int argc = sizeof(argv) / sizeof(char *);
    CmdArgs *cmd_args = new_cmd_args();

    char *result = parse_cmd_args(argc, (char *const *) argv, cmd_args);

    MU_EQUAL_INT(cmd_args->ready_to_compress, 0);

    // Free memory
    free_cmd_args(cmd_args);
    free(result);

    return 0;
}

static char *test_parse_cmd_args__extra_arguments()
{
    const char *argv[] = { "compressor", "dir/image.jpg", "dir/compressed.jpg", "extra"};

    int argc = sizeof(argv) / sizeof(char *);
    CmdArgs *cmd_args = new_cmd_args();

    char *result = parse_cmd_args(argc, (char *const *) argv, cmd_args);

    MU_EQUAL_INT(cmd_args->ready_to_compress, 0);
    MU_EQUAL_STR(cmd_args->path, "dir/image.jpg");
    MU_EQUAL_STR(cmd_args->output, "dir/compressed.jpg");
    MU_EQUAL_STR(result, "ERROR: unkown option 'extra'\n");

    // Free memory
    free_cmd_args(cmd_args);
    free(result);

    return 0;
}


static char *test_parse_cmd_args__no_output_path()
{
    const char *argv[] = { "compressor", "dir/image.jpg"};

    int argc = sizeof(argv) / sizeof(char *);
    CmdArgs *cmd_args = new_cmd_args();

    char *result = parse_cmd_args(argc, (char *const *) argv, cmd_args);

    MU_EQUAL_INT(cmd_args->ready_to_compress, 0);
    MU_EQUAL_STR(cmd_args->path, "dir/image.jpg");
    MU_ASSERT(cmd_args->output == NULL);
    MU_EQUAL_STR(result, "ERROR: OUTPUT path is not supplied\n");

    // Free memory
    free_cmd_args(cmd_args);
    free(result);

    return 0;
}


static char *test_parse_cmd_args__no_image_path()
{
    const char *argv[] = { "compressor", "--terms=5"};

    int argc = sizeof(argv) / sizeof(char *);
    CmdArgs *cmd_args = new_cmd_args();

    char *result = parse_cmd_args(argc, (char *const *) argv, cmd_args);

    MU_EQUAL_INT(cmd_args->ready_to_compress, 0);
    MU_ASSERT(cmd_args->path == NULL);
    MU_EQUAL_STR(result, "ERROR: IMAGE path is not supplied\n");

    // Free memory
    free_cmd_args(cmd_args);
    free(result);

    return 0;
}


static char *test_parse_cmd_args__default_terms_and_iterations()
{
   const char *argv[] = { "compressor",  "dir/image.jpg", "dir/compressed.jpg" };

    int argc = sizeof(argv) / sizeof(char *);
    CmdArgs *cmd_args = new_cmd_args();

    char *result = parse_cmd_args(argc, (char *const *) argv, cmd_args);

    MU_EQUAL_INT(cmd_args->ready_to_compress, 1);
    MU_EQUAL_INT(cmd_args->terms, 10);
    MU_EQUAL_INT(cmd_args->iterations, 3);
    MU_EQUAL_STR(cmd_args->path, "dir/image.jpg");
    MU_EQUAL_STR(cmd_args->output, "dir/compressed.jpg");
    MU_EQUAL_STR(result, "");

    // Free memory
    free_cmd_args(cmd_args);
    free(result);

    return 0;
}


static char *test_parse_cmd_args__benchmark()
{
   const char *argv[] = { "compressor",  "--benchmark" };

    int argc = sizeof(argv) / sizeof(char *);
    CmdArgs *cmd_args = new_cmd_args();

    char *result = parse_cmd_args(argc, (char *const *) argv, cmd_args);

    MU_EQUAL_INT(cmd_args->ready_to_compress, 1);
    MU_EQUAL_INT(cmd_args->benchmark, 1);
    MU_EQUAL_INT(cmd_args->terms, 30);
    MU_EQUAL_INT(cmd_args->iterations, 5);
    MU_EQUAL_STR(cmd_args->path, "images/marmite_500x500.jpg");
    MU_EQUAL_STR(cmd_args->output, "images/marmite_output_500x500.bmp");
    MU_EQUAL_STR(result, "");

    // Free memory
    free_cmd_args(cmd_args);
    free(result);

    return 0;
}


static char *test_benchmark_options()
{
    CmdArgs *cmd_args = new_cmd_args();
    benchmark_options(cmd_args);

    MU_EQUAL_INT(cmd_args->ready_to_compress, 1);
    MU_EQUAL_INT(cmd_args->benchmark, 1);
    MU_EQUAL_INT(cmd_args->terms, 30);
    MU_EQUAL_INT(cmd_args->iterations, 5);
    MU_EQUAL_STR(cmd_args->path, "images/marmite_500x500.jpg");
    MU_EQUAL_STR(cmd_args->output, "images/marmite_output_500x500.bmp");

    // Free memory
    free_cmd_args(cmd_args);

    return 0;
}


char *load_all_cmd_args_tests(void)
{
    MU_RUN_TEST(test_parse_cmd_args__all_options_supplied);
    MU_RUN_TEST(test_parse_cmd_args__no_arguments);
    MU_RUN_TEST(test_parse_cmd_args__extra_arguments);
    MU_RUN_TEST(test_parse_cmd_args__no_output_path);
    MU_RUN_TEST(test_parse_cmd_args__no_image_path);
    MU_RUN_TEST(test_parse_cmd_args__default_terms_and_iterations);
    MU_RUN_TEST(test_parse_cmd_args__benchmark);
    MU_RUN_TEST(test_benchmark_options);
    MU_RUN_TEST(test_parse_cmd_args__no_text);
    return 0;
}