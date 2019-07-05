#ifndef INCLUDE_LOAD_IMAGE_H
#define INCLUDE_LOAD_IMAGE_H

/*

Loads an image from given path (PNG, JPG, BMP formats).

Inputs:
-------

path : path to the image.


Outputs:
-------

width, height : width and height of the image.

channels : number of color channels (3 for RGB, 1 for monochrome, 4 for RGB + alpha).

Returns : array of image pixel values for each channel, array length is `channels`.

*/
double **load_image(const char *path, int *width, int *height, int *channels);


/*

Convert the `image` data into separate arrays for each color (returned).

Inputs:
-------

image : image data received from stbi_load function.

width, height : width and height of the image.

channels : number of color channels (3 for RGB, 1 for monochrome, 4 for RGB + alpha).

Outputs:
-------

Returns : array of image pixel values for each channel, array length is `channels`.

*/
double **image_to_array(unsigned char *image, int width, int height, int channels);

#endif // INCLUDE_LOAD_IMAGE_H