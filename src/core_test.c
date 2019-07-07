#include <stdio.h>
#include <unistd.h>
#include "external/minunit.h"
#include "core.h"
#include "core_test.h"
#include "load_image.h"


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


char *load_all_core_tests(void)
{
    MU_RUN_TEST(test_compress_image);
    MU_RUN_TEST(test_compress_image_file);
    return 0;
}