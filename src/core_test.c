#include "external/minunit.h"
#include "core.h"
#include "core_test.h"
#include "load_image.h"

static char *test_compress_image()
{
    int channels;
    Matrix **matrices = load_image("images/test_100x100.jpg", &channels);

    // Matrix **result = compress_image(matrices, 10, 5, channels);

    // MU_EQUAL_INT(channels, 3);
    // MU_ASSERT(result != NULL);
    // MU_EQUAL_INT(result[0]->row_num, 12);

    // Free memory
    free_matrix(matrices[0]);
    free_matrix(matrices[1]);
    free_matrix(matrices[2]);
    free(matrices);
    matrices = NULL;

    // free_matrix(result[0]);
    // free_matrix(result[1]);
    // free_matrix(result[2]);
    // free(result);
    // result = NULL;

    return 0;
}


char *load_all_core_tests(void)
{
    MU_RUN_TEST(test_compress_image);
    return 0;
}