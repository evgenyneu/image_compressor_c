#ifndef INCLUDE_CMD_ARGS_H
#define INCLUDE_CMD_ARGS_H

// Contains arguments passed from the command line
typedef struct
{
    // Path to the image file to compress.
    const char *path;

    // Path to the compressed image file that will be created.
    const char *output;

    // The number of terms for the singular value expansion. Higher number will produce better quality.
    int terms;

    // Number of terms in the singular value expansion.
    int iterations;
} CmdArgs;

/*

Parses command line arguments

Inputs:
-------

argc : the length of the `argv` array.

argv :  the array containing arguments that is supplied to the `main` function.

iterations : Number of terms in the singular value expansion.


Outputs:
-------

Returns : 0 if arguments are successfully parsed, or 1 if there was an error.

*/
int parse_cmd_args(int argc, const char *argv[]);

#endif // INCLUDE_CMD_ARGS_H
