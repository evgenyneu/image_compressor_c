#include "external/minunit.h"
#include "load_image.h"
#include "load_image_test.h"

static char * test_load_image() {
    int width, height, channels;
    double **matrices = load_image("images/test_3x3.bmp", &width, &height, &channels);

    // Red
    mu_equal_double(matrices[0][0], 80.0);
    mu_equal_double(matrices[0][1], 60.0);
    mu_equal_double(matrices[0][2], 0.0);
    mu_equal_double(matrices[0][3], 150.0);
    mu_equal_double(matrices[0][4], 120.0);
    mu_equal_double(matrices[0][5], 100.0);
    mu_equal_double(matrices[0][6], 255.0);
    mu_equal_double(matrices[0][7], 220.0);
    mu_equal_double(matrices[0][8], 200.0);

    // Green
    mu_equal_double(matrices[1][0], 85.0);
    mu_equal_double(matrices[1][1], 65.0);
    mu_equal_double(matrices[1][2], 5.0);
    mu_equal_double(matrices[1][3], 155.0);
    mu_equal_double(matrices[1][4], 125.0);
    mu_equal_double(matrices[1][5], 105.0);
    mu_equal_double(matrices[1][6], 255.0);
    mu_equal_double(matrices[1][7], 225.0);
    mu_equal_double(matrices[1][8], 205.0);

    // Blue
    mu_equal_double(matrices[2][0], 90.0);
    mu_equal_double(matrices[2][1], 70.0);
    mu_equal_double(matrices[2][2], 10.0);
    mu_equal_double(matrices[2][3], 160.0);
    mu_equal_double(matrices[2][4], 130.0);
    mu_equal_double(matrices[2][5], 110.0);
    mu_equal_double(matrices[2][6], 255.0);
    mu_equal_double(matrices[2][7], 230.0);
    mu_equal_double(matrices[2][8], 210.0);

    free(matrices[0]);
    free(matrices[1]);
    free(matrices[2]);
    free(matrices);
    matrices = NULL;

    return 0;
}

static char * test_image_to_array() {
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

    double **matrices = image_to_array(image, width, height, channels);
    mu_assert(matrices[0][0] == 0);
    mu_assert(matrices[0][1] == 1);
    mu_assert(matrices[0][2] == 2);
    mu_assert(matrices[0][4] == 4);
    mu_assert(matrices[0][5] == 5);

    // Free memory
    free(image);
    image = NULL;
    free(matrices[0]);
    free(matrices);
    matrices = NULL;

    return 0;
}

char * all_load_image_tests(void) {
    mu_run_test(test_load_image);
    mu_run_test(test_image_to_array);
    return 0;
}