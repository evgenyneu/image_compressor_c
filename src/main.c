#include <stdlib.h>
#include <stdio.h>
#include "cmd_args.h"
#include "core.h"

int main(int argc, char *argv[])
{
    CmdArgs *cmd_args = new_cmd_args();

    char *result = parse_cmd_args(argc, argv, cmd_args);
    printf("%s", result);

    if (cmd_args->ready_to_compress)
    {
        printf("\nCompresssing to %s\n", cmd_args->output);
        compress_from_command_line_options(cmd_args);
        printf("Done\n");
        free_cmd_args(cmd_args);
        cmd_args = NULL;
        return EXIT_SUCCESS;
    }

    free_cmd_args(cmd_args);
    cmd_args = NULL;
    return EXIT_FAILURE;
}