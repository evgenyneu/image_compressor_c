#include "external/minunit.h"
#include "load_image.h"

static char * test_load_image() {
    load_image("images/test_3x3_gray.bmp");
    mu_assert(7 == 7);
    return 0;
}

static char * test_image_to_array() {
    unsigned char *image;
    int width = 2;
    int height = 3;
    int channels = 1;
    int i;
    int pixel_num = width * height;

    image = malloc(pixel_num * channels * sizeof(unsigned char));

    for(i = 0; i < pixel_num; i++) {
       image[i] = i;
    }

    unsigned char **matrices = malloc(channels * sizeof(unsigned char *));

    image_to_array(image, width, height, channels, matrices);
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

char * all_load_image_tests() {
    mu_run_test(test_load_image);
    mu_run_test(test_image_to_array);
    return 0;
}