#define STB_IMAGE_IMPLEMENTATION
#include "external/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "external/stb_image_write.h"
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

    if (*channels == 4)
    {
        // We do not want the 4th alpha channel
        *channels = 3;
    }

    free(image);
    image = NULL;

    return matrices;
}

void save_image(const char *path, Matrix **matrices, int channels)
{
    if (channels == 0)
    {
        perror("Can not save image to disc for zero channels.");
        exit(EXIT_FAILURE);
    }

    unsigned char *image = matrix_to_image(matrices, channels);
    int width = matrices[0]->col_num;
    int height = matrices[0]->row_num;

    stbi_write_bmp(path, width, height, channels, image);
}


Matrix **image_to_matrix(unsigned char *image, int width, int height, int channels)
{
    int channel, pixel;
    int pixel_num = width * height;
    int allocate_channels = channels;

    if (channels == 4)
    {
        allocate_channels = 3; // Skip the alpha channel
    }

    Matrix **matrices = malloc((unsigned long) allocate_channels * sizeof(Matrix *));
    Matrix *single_matrix = NULL;

    // Allocate data
    for (channel = 0; channel < allocate_channels; channel++)
    {
        single_matrix = new_matrix(height, width);
        matrices[channel] =  single_matrix;
    }

    for (pixel = 0; pixel < pixel_num; pixel++)
    {
        for (channel = 0; channel < allocate_channels; channel++)
        {
            matrices[channel]->data[pixel] = image[pixel * channels + channel];
        }
    }

    return matrices;
}


unsigned char *matrix_to_image(Matrix **matrices, int channels)
{
    if (channels == 0)
    {
        perror("Can not save data for zero channels.");
        exit(EXIT_FAILURE);
    }

    int pixel_num = matrices[0]->col_num * matrices[0]->row_num;
    int pixel, channel;
    unsigned char *data;

    data = malloc((unsigned long)(pixel_num * channels) * sizeof(unsigned char));

    if (data == NULL)
    {
        perror("Can not allocate memory for the image.");
        exit(EXIT_FAILURE);
    }

    for (pixel = 0; pixel < pixel_num; pixel++)
    {
        for(channel = 0; channel < channels; channel++)
        {
            double value = matrices[channel]->data[pixel];
            unsigned char output_value;

            // Make sure the pixel value is in [0, 255] range
            if (value > 255)
            {
                output_value  = 255;
            }
            else if (value < 0)
            {
                output_value = 0;
            }
            else
            {
                output_value = (unsigned char) value;
            }

            data[pixel * channels + channel] = output_value;
        }
    }

    return data;
}
