#define STB_IMAGE_IMPLEMENTATION
#include "external/stb_image.h"
#include "load_image.h"

Matrix **load_image(const char *path,  int *channels)
{
    int width, height;
    unsigned char *image = stbi_load(path, &width, &height, channels, 0);

    if (image == NULL)
    {
        perror("Error loading image");
        exit(EXIT_FAILURE);
    }

    Matrix **matrices = image_to_matrix(image, width, height, *channels);

    free(image);
    image = NULL;

    return matrices;
}


Matrix **image_to_matrix(unsigned char *image, int width, int height, int channels)
{
    int i, pixel;
    int pixel_num = width * height;
    Matrix **matrices = malloc((unsigned long) channels * sizeof(Matrix *));
    Matrix *single_matrix = NULL;

    // Allocate data
    for (i = 0; i < channels; i++)
    {
        single_matrix = new_matrix(height, width);
        matrices[i] =  single_matrix;
    }

    for (pixel = 0; pixel < pixel_num; pixel++)
    {
        for (i = 0; i < channels; i++)
        {
            matrices[i]->data[pixel] = image[pixel * channels + i];
        }
    }

    return matrices;
}
