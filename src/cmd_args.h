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

    // Contains 1 if arguments were passed successfully, or 0 if there was an error.
    int success;
} CmdArgs;


/*

Free memory from `cmd_args`.

Inputs:
-------

cmd_args : command line arguments.

*/
void free_cmd_args(CmdArgs *cmd_args);


/*

Parses command line arguments

Inputs:
-------

argc : the length of the `argv` array.

argv :  the array containing arguments that is supplied to the `main` function.

iterations : Number of terms in the singular value expansion.

cmd_args : parsed command line arguments.


Outputs:
-------

Returns : text from the parser that is intended to be shown to user.

*/
char *parse_cmd_args(int argc, const char *argv[], CmdArgs *cmd_args);

#endif // INCLUDE_CMD_ARGS_H
