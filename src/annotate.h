/*

Adds an annotation to the image locate at `path`.
The annotation includes the compression level and the `terms` settings used.
Image Magic's `convert` command needs to be installed on the system.

Inputs:
-------

path : Path to the image.

terms : The `terms` parameter that was used to compress the image.

compression : The compression factor (the ratio of the original image size to the compressed one).

width : image width.

*/
void annotate(char *path, int terms, double compression, int width);