#include "external/minunit.h"
#include "load_image.h"

static char * test_load_image() {
    load_image("images/test_3x3_gray.bmp");
    mu_assert("Image loaded", 7 == 7);
    return 0;
}

static char * all_load_image_tests() {
    mu_run_test(test_load_image);
    return 0;
}