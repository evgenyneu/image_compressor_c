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

// Convert the `image` data into separate arrays for each color channel stored in `matrices`.
void image_to_array(unsigned char *image, int width, int height, int channels,
                    unsigned char **matrices) {
    int i;
    int pixel;
    int pixel_num = width * height;
    unsigned char *single_matrix;

    for (i = 0; i < channels; i++) {
        single_matrix = malloc(pixel_num * sizeof(unsigned char));

        if (single_matrix == NULL) {
            printf("Error allocating matrix data \n");
            exit(EXIT_FAILURE);
        }

        matrices[i] =  single_matrix;

        for (pixel = 0; pixel < pixel_num; pixel++) {
            single_matrix[pixel] = image[pixel * channels + i];
        }
    }
}