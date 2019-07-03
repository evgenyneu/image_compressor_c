#include <stdio.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "external/stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "external/stb_image.h"

int main(void)
{
    int width, height, channels;
    unsigned char *image = stbi_load("images/test_3x3_gray.bmp",
                                    &width,
                                    &height,
                                    &channels,
                                    0);

    printf("Image %d x %d. Channels: %d \n", width, height, channels);

    int i;
    int pixel_num = width * height;

    for (i = 0; i < pixel_num; i++) {
        printf("%d: %d\n", i, image[i * channels]);
    }

    stbi_write_bmp("images/out.bmp", width, height, channels, image);

    stbi_image_free(image);

    return 0;
}