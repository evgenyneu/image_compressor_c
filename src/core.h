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

#endif // INCLUDE_CORE_H