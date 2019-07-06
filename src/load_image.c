#define STB_IMAGE_IMPLEMENTATION
#include "external/stb_image.h"
#include "load_image.h"

Matrix **load_image(const char *path, int *width, int *height, int *channels)
{
    unsigned char *image = stbi_load(path, width, height, channels, 0);

    if (image == NULL)
    {
        perror("Error loading image");
        exit(EXIT_FAILURE);
    }

    Matrix **matrices = image_to_matrix(image, *width, *height, *channels);

    free(image);
    image = NULL;

    return matrices;
}


double **image_to_array(unsigned char *image, int width, int height, int channels)
{
    int i, pixel;
    int pixel_num = width * height;
    double **matrices = malloc((unsigned long) channels * sizeof(double *));
    double *single_matrix = NULL;

    // Allocate data
    for (i = 0; i < channels; i++)
    {
        single_matrix = malloc((unsigned long)pixel_num * sizeof(double));

        if (single_matrix == NULL)
        {
            perror("Error allocating matrix data");
            exit(EXIT_FAILURE);
        }

        matrices[i] =  single_matrix;
    }

    for (pixel = 0; pixel < pixel_num; pixel++)
    {
        for (i = 0; i < channels; i++)
        {
            matrices[i][pixel] = image[pixel * channels + i];
        }
    }

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
