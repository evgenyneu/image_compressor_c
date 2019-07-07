#define STB_IMAGE_IMPLEMENTATION
#include "external/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "external/stb_image_write.h"
#include "load_image.h"
#include "string_util.h"

Matrix **load_image(const char *path, int *matrix_num)
{
    int width, height, channels;
    unsigned char *image = stbi_load(path, &width, &height, &channels, 0);

    if (image == NULL)
    {
        perror("Error loading image");
        exit(EXIT_FAILURE);
    }

    Matrix **matrices = image_to_matrix(image, width, height, channels, matrix_num);

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

    char *path_lowercase = string_to_lower(path);

    if (string_ends_with(path_lowercase, ".jpg") == 1 || string_ends_with(path_lowercase, ".jpeg") == 1)
    {
        stbi_write_jpg(path, width, height, channels, image, 80);
    }
    else if (string_ends_with(path_lowercase, ".bmp") == 1)
    {
        stbi_write_bmp(path, width, height, channels, image);
    }
    else
    {
        perror("Incorrect output string name. Only JPG, or BMP string are supported.");
        exit(EXIT_FAILURE);
    }

    free(path_lowercase);
    path_lowercase = NULL;
}



Matrix **image_to_matrix(unsigned char *image, int width, int height, int channels, int *matrix_num)
{
    int channel, pixel;
    int pixel_num = width * height;
    *matrix_num = channels;

    if (channels == 4)
    {
        *matrix_num = 3; // Skip the alpha channel
    }

    Matrix **matrices = malloc((unsigned long) (*matrix_num) * sizeof(Matrix *));
    Matrix *single_matrix = NULL;

    // Allocate data
    for (channel = 0; channel < (*matrix_num); channel++)
    {
        single_matrix = new_matrix(height, width);
        matrices[channel] =  single_matrix;
    }

    for (pixel = 0; pixel < pixel_num; pixel++)
    {
        for (channel = 0; channel < (*matrix_num); channel++)
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
