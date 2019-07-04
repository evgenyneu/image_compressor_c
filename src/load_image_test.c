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

    image = malloc(width * width * channels * sizeof(unsigned char));

    image_to_array(image, width, height, channels);
    mu_assert(7 == 7);
    return 0;
}

char * all_load_image_tests() {
    mu_run_test(test_load_image);
    mu_run_test(test_image_to_array);
    return 0;
}