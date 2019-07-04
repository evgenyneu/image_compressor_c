#define STB_IMAGE_IMPLEMENTATION
#include "external/stb_image.h"

void load_image(const char *path) {
    int width, height, channels;
    unsigned char *image = stbi_load(path, &width, &height, &channels, 0);

    if (image == NULL) {
        printf("Error loading image %s \n", path);
        exit(EXIT_FAILURE);
    }
}


void image_to_array(unsigned char *image, int width, int height, int channels) {
    int i = 2;
}