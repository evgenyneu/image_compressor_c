#include "external/minunit.h"
#include "load_image.h"
#include "load_image_test.h"

static char *test_load_image()
{
    int channels;
    Matrix **matrices = load_image("images/test_3x3.bmp", &channels);

    // Red
    MU_EQUAL_INT(matrices[0]->row_num, 3);
    MU_EQUAL_INT(matrices[0]->col_num, 3);
    MU_EQUAL_DOUBLE(matrices[0]->data[0], 80.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[1], 60.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[2], 0.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[3], 150.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[4], 120.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[5], 100.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[6], 255.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[7], 220.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[8], 200.0);

    // Green
    MU_EQUAL_INT(matrices[1]->row_num, 3);
    MU_EQUAL_INT(matrices[1]->col_num, 3);
    MU_EQUAL_DOUBLE(matrices[1]->data[0], 85.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[1], 65.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[2], 5.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[3], 155.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[4], 125.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[5], 105.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[6], 255.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[7], 225.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[8], 205.0);

    // Blue
    MU_EQUAL_INT(matrices[2]->row_num, 3);
    MU_EQUAL_INT(matrices[2]->col_num, 3);
    MU_EQUAL_DOUBLE(matrices[2]->data[0], 90.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[1], 70.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[2], 10.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[3], 160.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[4], 130.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[5], 110.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[6], 255.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[7], 230.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[8], 210.0);

    // Free memory
    free_matrix(matrices[0]);
    free_matrix(matrices[1]);
    free_matrix(matrices[2]);
    free(matrices);
    matrices = NULL;

    return 0;
}


static char *test_image_to_matrix()
{
    unsigned char *image;
    int width = 2;
    int height = 3;
    int channels = 1;
    int i;
    int pixel_num = width * height;

    image = malloc((unsigned long) (pixel_num * channels) * sizeof(unsigned char));

    for(i = 0; i < pixel_num; i++) {
       image[i] = (unsigned char)i;
    }

    Matrix **matrices = image_to_matrix(image, width, height, channels);

    MU_EQUAL_INT(channels, 1);
    MU_EQUAL_INT(matrices[0]->row_num, 3);
    MU_EQUAL_INT(matrices[0]->col_num, 2);
    MU_ASSERT(matrices[0]->data[0] == 0);
    MU_ASSERT(matrices[0]->data[1] == 1);
    MU_ASSERT(matrices[0]->data[2] == 2);
    MU_ASSERT(matrices[0]->data[4] == 4);
    MU_ASSERT(matrices[0]->data[5] == 5);

    // Free memory
    free(image);
    image = NULL;
    free_matrix(matrices[0]);
    free(matrices);
    matrices = NULL;

    return 0;
}


static char *test_matrix_to_image()
{
    int row_num = 3;
    int col_num = 2;
    int channels = 3;
    int channel;
    Matrix **matrices = malloc((unsigned long) channels * sizeof(Matrix *));

    for (channel = 0; channel < channels; channel++)
    {
        double *image_data = malloc((unsigned long) (row_num * col_num) * sizeof(double)); 
        matrices[channel] = new_matrix_from_array(image_data, row_num, col_num);
    }

    unsigned char *image = matrix_to_image(matrices, channel);

    // Matrix **matrices = image_to_matrix(image, width, height, channels);

    // MU_EQUAL_INT(channels, 1);
    // MU_EQUAL_INT(matrices[0]->row_num, 3);
    // MU_EQUAL_INT(matrices[0]->col_num, 2);
    // MU_ASSERT(matrices[0]->data[0] == 0);
    // MU_ASSERT(matrices[0]->data[1] == 1);
    // MU_ASSERT(matrices[0]->data[2] == 2);
    // MU_ASSERT(matrices[0]->data[4] == 4);
    // MU_ASSERT(matrices[0]->data[5] == 5);

    // // Free memory
    // free(image);
    // image = NULL;
    // free_matrix(matrices[0]);
    // free(matrices);
    // matrices = NULL;

    return 0;
}

char *load_all_image_tests(void)
{
    MU_RUN_TEST(test_load_image);
    MU_RUN_TEST(test_image_to_matrix);
    MU_RUN_TEST(test_matrix_to_image);
    return 0;
}