#include "external/minunit.h"
#include "load_image.h"
#include "load_image_test.h"

static char *test_load_image()
{
    int matrix_num = 0;
    Matrix **matrices = load_image("images/test_3x3.bmp", &matrix_num);

    MU_EQUAL_INT(matrix_num, 3);

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


static char *test_save_image()
{
    // Red data
    Matrix *matrix1 = new_matrix(3, 2);
    matrix1->data[0] = 0;
    matrix1->data[1] = 50;
    matrix1->data[2] = 100;
    matrix1->data[3] = 150;
    matrix1->data[4] = 200;
    matrix1->data[5] = 250;

    // Green data
    Matrix *matrix2 = new_matrix(3, 2);
    matrix2->data[0] = 1;
    matrix2->data[1] = 51;
    matrix2->data[2] = 101;
    matrix2->data[3] = 151;
    matrix2->data[4] = 201;
    matrix2->data[5] = 251;

    // Blue data
    Matrix *matrix3 = new_matrix(3, 2);
    matrix3->data[0] = 2;
    matrix3->data[1] = 52;
    matrix3->data[2] = 102;
    matrix3->data[3] = 152;
    matrix3->data[4] = 202;
    matrix3->data[5] = 252;

    Matrix **matrices = malloc(3 * sizeof(Matrix *));
    matrices[0] = matrix1;
    matrices[1] = matrix2;
    matrices[2] = matrix3;

    save_image("images/test_output_3x2.bmp", matrices, 3);

    // Verify the image
    // --------------

    int matrix_num;
    Matrix **matrices_read = load_image("images/test_output_3x2.bmp", &matrix_num);

    MU_EQUAL_INT(matrix_num, 3);

    // Red
    MU_EQUAL_INT(matrices[0]->row_num, 3);
    MU_EQUAL_INT(matrices[0]->col_num, 2);
    MU_EQUAL_DOUBLE(matrices[0]->data[0], 0.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[1], 50.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[2], 100.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[3], 150.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[4], 200.0);
    MU_EQUAL_DOUBLE(matrices[0]->data[5], 250.0);

    // Green
    MU_EQUAL_INT(matrices[1]->row_num, 3);
    MU_EQUAL_INT(matrices[1]->col_num, 2);
    MU_EQUAL_DOUBLE(matrices[1]->data[0], 1.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[1], 51.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[2], 101.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[3], 151.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[4], 201.0);
    MU_EQUAL_DOUBLE(matrices[1]->data[5], 251.0);


    // Blue
    MU_EQUAL_INT(matrices[2]->row_num, 3);
    MU_EQUAL_INT(matrices[2]->col_num, 2);
    MU_EQUAL_DOUBLE(matrices[2]->data[0], 2.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[1], 52.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[2], 102.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[3], 152.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[4], 202.0);
    MU_EQUAL_DOUBLE(matrices[2]->data[5], 252.0);


    // Free memory
    free_matrix(matrices[0]);
    free_matrix(matrices[1]);
    free_matrix(matrices[2]);
    free(matrices);
    matrices = NULL;
    matrix1 = NULL;
    matrix2 = NULL;
    matrix3 = NULL;

    free_matrix(matrices_read[0]);
    free_matrix(matrices_read[1]);
    free_matrix(matrices_read[2]);
    free(matrices_read);
    matrices_read = NULL;

    return 0;
}


static char *test_image_to_matrix()
{
    unsigned char *image;
    int width = 2;
    int height = 3;
    int channels = 1;
    int matrix_num;
    int i;
    int pixel_num = width * height;

    image = malloc((unsigned long) (pixel_num * channels) * sizeof(unsigned char));

    for(i = 0; i < pixel_num; i++) {
       image[i] = (unsigned char)i;
    }

    Matrix **matrices = image_to_matrix(image, width, height, channels, &matrix_num);

    MU_EQUAL_INT(matrix_num, 1);
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
    int channel;
    int pixel;
    int pixel_num = row_num * col_num;
    Matrix **matrices = malloc(3 * sizeof(Matrix *));

    for (channel = 0; channel < 3; channel++)
    {
        double *image_data = malloc((unsigned long) (row_num * col_num) * sizeof(double)); 
        Matrix *matrix = new_matrix_from_array(image_data, row_num, col_num);
        matrices[channel] = matrix;

        for (pixel = 0; pixel < pixel_num; pixel++)
        {
            matrix->data[pixel] = pixel_num * channel + pixel;
        }
    }

    // Set some pixels to be outsede [0, 255] range
    matrices[0]->data[5] = -1;
    matrices[1]->data[5] = 256;

    unsigned char *image = matrix_to_image(matrices, 3);

    MU_EQUAL_INT(image[0], 0);
    MU_EQUAL_INT(image[1], 6);
    MU_EQUAL_INT(image[2], 12);

    MU_EQUAL_INT(image[3], 1);
    MU_EQUAL_INT(image[4], 7);
    MU_EQUAL_INT(image[5], 13);

    MU_EQUAL_INT(image[6], 2);
    MU_EQUAL_INT(image[7], 8);
    MU_EQUAL_INT(image[8], 14);

    MU_EQUAL_INT(image[15], 0); // The pixel was changed from -1 to 0
    MU_EQUAL_INT(image[16], 255); // The pixel was changed from 256 to 255


    // Free memory
    free_matrix(matrices[0]);
    free_matrix(matrices[1]);
    free_matrix(matrices[2]);
    free(matrices);
    matrices = NULL;

    free(image);
    image = NULL;

    return 0;
}


char *load_all_image_tests(void)
{
    MU_RUN_TEST(test_load_image);
    MU_RUN_TEST(test_image_to_matrix);
    MU_RUN_TEST(test_matrix_to_image);
    MU_RUN_TEST(test_save_image);
    return 0;
}