#ifndef INCLUDE_CORE_H
#define INCLUDE_CORE_H


#include "linear_algebra.h"

/*

Compresses the image data using singular value expansion.

Inputs:
-------

matrices : array of matrices containing image data for each color chanel. The size of the array is `channels`.

terms :  The number of terms for the singular value expansion. Higher number will produce better quality.

iterations : Number of terms in the singular value expansion.


Outputs:
-------

Returns : matrices containing data each channel for the compressed image, array length is `channels`.

*/
Matrix **compress_image(Matrix **matrices, int terms, int iterations, int channels);


/*

Compresses the image and the output file.

Inputs:
-------

path : path to the image file to compress.

output : path to the output image file that will be created.

terms :  The number of terms for the singular value expansion. Higher number will produce better quality.

iterations : Number of terms in the singular value expansion.

*/
void compress_image_file(const char *path, const char *output, int terms, int iterations);


#endif // INCLUDE_CORE_H