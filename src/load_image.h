/*
Loading data from and saving data to image files.
*/

#ifndef INCLUDE_LOAD_IMAGE_H
#define INCLUDE_LOAD_IMAGE_H

#include "linear_algebra.h"

/*

Loads an image from given path (PNG, JPG, BMP formats).

Inputs:
-------

path : path to the image.


Outputs:
-------

channels : number of color channels (3 for RGB, 1 for monochrome, 4 for RGB + alpha).

Returns : matrices containing data each channel, array length is `channels`.

*/
Matrix **load_image(const char *path, int *channels);


/*

Saves matrices to an image.

Inputs:
-------

path : path to the image, with any of the following extensions: jpg, png, bmp.

matrices: matrices containing data each channel, array length is `channels`.

channels : number of color channels (3 for RGB, 1 for monochrome, 4 for RGB + alpha).

*/
void save_image(const char *path, Matrix **matrices, int channels);


/*

Convert the `image` data into separate arrays for each color (returned).

Inputs:
-------

image : image data received from stbi_load function.

width, height : width and height of the image.

channels : number of color channels (3 for RGB, 1 for monochrome, 4 for RGB + alpha).

Outputs:
-------

Returns : matrices containing data each channel, array length is `channels`.

*/
Matrix **image_to_matrix(unsigned char *image, int width, int height, int channels);


/*

Convert array of matrices that contain image data into a single image data.

Inputs:
-------

matrices: matrices containing data each channel, array length is `channels`.

channels : number of color channels (3 for RGB, 1 for monochrome, 4 for RGB + alpha).

Outputs:
-------

Returns : image data ready to be saved to disk with stbi_write_* functions.

*/
unsigned char *matrix_to_image(Matrix **matrices, int channels);



#endif // INCLUDE_LOAD_IMAGE_H