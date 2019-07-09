#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "external/parg.h"
#include "cmd_args.h"


CmdArgs *new_cmd_args(void)
{
    CmdArgs *cmd_args = malloc(sizeof(CmdArgs));
    cmd_args->path = NULL;
    cmd_args->output = NULL;
    return cmd_args;
}


void free_cmd_args(CmdArgs *cmd_args)
{
    free(cmd_args->path);
    free(cmd_args->output);
    free(cmd_args);
}


char *parse_cmd_args(int argc, char *const argv[], CmdArgs *cmd_args)
{
    struct parg_state ps;
	int c;
    const struct parg_option po_def[] = {
        { "terms", PARG_REQARG, NULL, 't' },
        { "iterations", PARG_REQARG, NULL, 'i' },
        { "help", PARG_NOARG, NULL, 'h' },
        { 0, 0, 0, 0 }
    };
    int li = -1;

	parg_init(&ps);

    char *output_text = malloc(100 * 1024 * sizeof(char));
    strcpy(output_text, "");
    char buffer[1024];

    const char help[] = "Compress an image using singular value decomposition\n\n"
        "Usage: \n\n"
        "   compressor [--help] [--terms=10] [--iterations=5] IMAGE OUTPUT\n\n"
        "IMAGE :  path to the image to compress\n"
        "OUTPUT :  path to the compressed image that will be created\n"
        "--terms :  number of terms in the singular value expansion\n"
        "--iterations :  number of iterations of the power method\n"
        "--help :  show this message\n";

	while ((c = parg_getopt_long(&ps,  argc, argv, "ma", po_def, &li)) != -1) {
		switch (c) {
		case 1:
			sprintf(buffer, "nonoption '%s'\n", ps.optarg);
            strcat(output_text, buffer);
			break;
		case 'h':
            sprintf(buffer, "%s", help);
            strcat(output_text, buffer);
			return NULL;
			break;
		case 't':
			sprintf(buffer, "option --terms with argument '%s'\n", ps.optarg);
            strcat(output_text, buffer);
			break;
        case 'i':
			sprintf(buffer, "option --iterations with argument '%s'\n", ps.optarg);
            strcat(output_text, buffer);
			break;
		case '?':
		case ':':
            switch (ps.optopt)
            {
                case 't':
                    sprintf(buffer, "option --terms requires an argument. Example: --terms=10\n");
                    strcat(output_text, buffer);
                    break;

                case 'i':
                    sprintf(buffer, "option --iterations requires an argument. Example: --iterations=3\n");
                    strcat(output_text, buffer);
                    break;

                default:
                    sprintf(buffer, "unknown option %c\n", ps.optopt);
                    strcat(output_text, buffer);
                    break;
            }
            cmd_args->success = 0;
            return output_text;
		default:
			sprintf(buffer, "error: unhandled option -%c\n", c);
            strcat(output_text, buffer);
			cmd_args->success = 0;
            return output_text;
			break;
		}
	}

    if (argc == 1)
    {
        // No options supplied
        strcat(output_text, help);
    }

    cmd_args->success = 1;
    return output_text;
}