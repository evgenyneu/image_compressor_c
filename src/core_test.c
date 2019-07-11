#include <stdio.h>
#include <unistd.h>
#include "external/minunit.h"
#include "core.h"
#include "core_test.h"
#include "load_image.h"
#include "cmd_args.h"
#include "string_util.h"


static char *test_compress_image()
{
    int matrix_num;
    Matrix **matrices = load_image("images/test_100x100.jpg", &matrix_num);

    Matrix **result = compress_image(matrices, 3, 5, matrix_num);

    MU_EQUAL_INT(matrix_num, 3);
    MU_ASSERT(result != NULL);
    MU_EQUAL_INT(result[0]->row_num, 100);
    MU_EQUAL_INT(result[0]->col_num, 100);
    MU_EQUAL_INT(result[1]->row_num, 100);
    MU_EQUAL_INT(result[1]->col_num, 100);
    MU_EQUAL_INT(result[2]->row_num, 100);
    MU_EQUAL_INT(result[2]->col_num, 100);

    // Free memory
    free_matrix(matrices[0]);
    free_matrix(matrices[1]);
    free_matrix(matrices[2]);
    free(matrices);
    matrices = NULL;

    free_matrix(result[0]);
    free_matrix(result[1]);
    free_matrix(result[2]);
    free(result);
    result = NULL;

    return 0;
}

static char *test_compress_image_file()
{
    const char *output_path = "images/test_output_100x100.jpg";

    if (access(output_path, F_OK) != -1)
    {
        if (remove(output_path) != 0)
        {
            printf("Unable to delete the file");
        }
    }

    MU_ASSERT(access(output_path, F_OK) == -1);

    compress_image_file("images/test_100x100.jpg", output_path, 3, 5);

    // Check image exists
    MU_ASSERT(access(output_path, F_OK) != -1);

    // Delete test file
    if (remove(output_path) != 0)
    {
        printf("Unable to delete the file");
    }

    return 0;
}


static char *test_compress_3_by_3_image_file()
{
    const char *output_path = "images/test_3x3_output.bmp";

    if (access(output_path, F_OK) != -1)
    {
        if (remove(output_path) != 0)
        {
            printf("Unable to delete the file");
        }
    }

    MU_ASSERT(access(output_path, F_OK) == -1);

    compress_image_file("images/test_3x3.bmp", output_path, 1, 1);

    // Check image exists
    MU_ASSERT(access(output_path, F_OK) != -1);

    // Verify output image
    // -----------

    int matrix_num;
    Matrix **matrices = load_image(output_path, &matrix_num);

    MU_EQUAL_INT(matrix_num, 3);


    // Red

    Matrix *matrix = matrices[0];
    MU_EQUAL_INT(matrix->row_num, 3);
    MU_EQUAL_INT(matrix->col_num, 3);
    MU_EQUAL_DOUBLE(matrix->data[0], 59.0);
    MU_EQUAL_DOUBLE(matrix->data[1], 49.0);
    MU_EQUAL_DOUBLE(matrix->data[2], 41.0);
    MU_EQUAL_DOUBLE(matrix->data[3], 145.0);
    MU_EQUAL_DOUBLE(matrix->data[4], 122.0);
    MU_EQUAL_DOUBLE(matrix->data[5], 102.0);
    MU_EQUAL_DOUBLE(matrix->data[6], 255.0);
    MU_EQUAL_DOUBLE(matrix->data[7], 221.0);
    MU_EQUAL_DOUBLE(matrix->data[8], 185.0);


    // Green

    matrix = matrices[1];
    MU_EQUAL_INT(matrix->row_num, 3);
    MU_EQUAL_INT(matrix->col_num, 3);
    MU_EQUAL_DOUBLE(matrix->data[0], 64.0);
    MU_EQUAL_DOUBLE(matrix->data[1], 54.0);
    MU_EQUAL_DOUBLE(matrix->data[2], 46.0);
    MU_EQUAL_DOUBLE(matrix->data[3], 150.0);
    MU_EQUAL_DOUBLE(matrix->data[4], 128.0);
    MU_EQUAL_DOUBLE(matrix->data[5], 107.0);
    MU_EQUAL_DOUBLE(matrix->data[6], 255.0);
    MU_EQUAL_DOUBLE(matrix->data[7], 226.0);
    MU_EQUAL_DOUBLE(matrix->data[8], 189.0);


    // Blue

    matrix = matrices[2];
    MU_EQUAL_INT(matrix->row_num, 3);
    MU_EQUAL_INT(matrix->col_num, 3);
    MU_EQUAL_DOUBLE(matrix->data[0], 69.0);
    MU_EQUAL_DOUBLE(matrix->data[1], 60.0);
    MU_EQUAL_DOUBLE(matrix->data[2], 50.0);
    MU_EQUAL_DOUBLE(matrix->data[3], 154.0);
    MU_EQUAL_DOUBLE(matrix->data[4], 134.0);
    MU_EQUAL_DOUBLE(matrix->data[5], 112.0);
    MU_EQUAL_DOUBLE(matrix->data[6], 255.0);
    MU_EQUAL_DOUBLE(matrix->data[7], 230.0);
    MU_EQUAL_DOUBLE(matrix->data[8], 194.0);


    // Delete test file
    if (remove(output_path) != 0)
    {
        printf("Unable to delete the file");
    }

    // Free memory
    // -------

    free_matrix(matrices[0]);
    free_matrix(matrices[1]);
    free_matrix(matrices[2]);
    free(matrices);
    matrices = NULL;

    return 0;
}


static char *test_compress_from_command_line_options()
{
    const char *output_path = "images/test_output_100x100.jpg";
    CmdArgs *cmd_args = new_cmd_args();
    cmd_args->path = copy_string("images/test_100x100.jpg");
    cmd_args->output = copy_string(output_path);
    cmd_args->terms = 3;
    cmd_args->iterations = 5;

    if (access(output_path, F_OK) != -1)
    {
        if (remove(output_path) != 0)
        {
            printf("Unable to delete the file");
        }
    }

    MU_ASSERT(access(output_path, F_OK) == -1);

    compress_from_command_line_options(cmd_args, 1);

    // Check image exists
    MU_ASSERT(access(output_path, F_OK) != -1);

    // Delete test file
    if (remove(output_path) != 0)
    {
        printf("Unable to delete the file");
    }

    // Free memory

    free_cmd_args(cmd_args);

    return 0;
}


char *load_all_core_tests(void)
{
    MU_RUN_TEST(test_compress_image);
    MU_RUN_TEST(test_compress_image_file);
    MU_RUN_TEST(test_compress_from_command_line_options);
    MU_RUN_TEST(test_compress_3_by_3_image_file);
    return 0;
}