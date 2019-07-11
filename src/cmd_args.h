#ifndef INCLUDE_CMD_ARGS_H
#define INCLUDE_CMD_ARGS_H


// Contains arguments passed from the command line
typedef struct
{
    // Path to the image file to compress.
    char *path;

    // Path to the compressed image file that will be created.
    char *output;

    // The number of terms for the singular value expansion. Higher number will produce better quality.
    int terms;

    // Number of terms in the singular value expansion.
    int iterations;

    // Contains 1 if all necessary arguments were supplied in order
    // to compress an image.
    // Contains 0 otherwise.
    int ready_to_compress;

    // Contains 1 the benchmark if this is a benchmark compression
    // Contains 0 otherwise.
    int benchmark;
} CmdArgs;


/*

Allocates memory for CmdArgs structure and initializes its members.


Outputs:
-------

Returns : a pointer to a newly allocated CmdArgs structure.

*/
CmdArgs *new_cmd_args(void);


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
char *parse_cmd_args(int argc, char *const argv[], CmdArgs *cmd_args);


/*

Assign options used for the benchmark.

Inputs:
-------

cmd_args : Command line options.

*/
void benchmark_options(CmdArgs *cmd_args);

#endif // INCLUDE_CMD_ARGS_H
