#ifndef INCLUDE_CORE_H
#define INCLUDE_CORE_H


#include "linear_algebra.h"
#include "cmd_args.h"

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

Calculate the size of the original image relative to the compressed image.

Inputs:
-------

width, height: width and height of the image in pixels.

terms :  The number of terms for the singular value expansion. Higher number will produce better quality.


Output:
-------

Returns: The size of the original image relative to the compressed image.

*/
double compression_ratio(int terms, int width, int height);


/*

Compresses the image and the output file.

Inputs:
-------

path : path to the image file to compress.

output : path to the compressed image file that will be created.

terms :  The number of terms for the singular value expansion. Higher number will produce better quality.

iterations : Number of terms in the singular value expansion.

Output:
-------

width, height: will be set to the width and height of the image.

*/
void compress_image_file(const char *path, const char *output, int terms, int iterations, int *width, int *height);


/*

Compresses the image according to the command line options.

Inputs:
-------

cmd_args : command line options.

silent : If 1 it does not show any output.

*/
void compress_from_command_line_options(CmdArgs *cmd_args, int silent);


#endif // INCLUDE_CORE_H