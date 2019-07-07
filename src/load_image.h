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

matrix_num : the size of the returned array. This the number of color channels (3 for RGB, 1 for monochrome).

Returns : matrices containing data for each channel, array length is `matrix_num`.

*/
Matrix **load_image(const char *path, int *matrix_num);


/*

Saves matrices to an image.

Inputs:
-------

path : path to the image, with any of the following extensions: jpg or bmp.

matrices: matrices containing data each channel, array length is `channels`.

channels : number of color channels (3 for RGB, 1 for monochrome, 4 for RGB + alpha).

*/
void save_image(const char *path, Matrix **matrices, int channels);


/*

Convert the `image` data into separate arrays for each color (returned).
The alpha channel is not converted.

Inputs:
-------

image : image data received from stbi_load function.

width, height : width and height of the image.

channels : number of color channels in the `image` (3 for RGB, 1 for monochrome, 4 for RGB + alpha).

Outputs:
-------

matrix_num : the size of the returned Matrix ** array. We do not want the alpha channel, therefore
    matrix_num will be 3 when channels=4.

Returns : matrices containing data each channel, array length is `matrix_num`.

*/
Matrix **image_to_matrix(unsigned char *image, int width, int height, int channels, int *matrix_num);


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