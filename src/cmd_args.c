#include <stdlib.h>
#include <stdio.h>
#include "external/parg.h"
#include "cmd_args.h"

void free_cmd_args(CmdArgs *cmd_args)
{
    free(cmd_args->path);
    free(cmd_args->output);
    free(cmd_args);
}

char *parse_cmd_args(int argc, const char *argv[], CmdArgs *cmd_args)
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

    char *output_text = malloc(10 * 1024 * sizeof(char));
    output_text[0] = "\0";

    const char help[] = "Compress an image using singular value decomposition\n\n"
        "Usage: \n\n"
        "   compressor [--help] [--terms=10] [--iterations=5] IMAGE OUTPUT\n\n"
        "IMAGE :  path to the image to compress\n"
        "OUTPUT :  path to the compressed image that will be created\n"
        "--terms :  number of terms in the singular value expansion\n"
        "--iterations :  number of iterations of the power method\n"
        "--help :  show this message\n";

	while ((c = parg_getopt_long(&ps, argc, argv, "ma", po_def, &li)) != -1) {
		switch (c) {
		case 1:
			sprintf(output_text, "nonoption '%s'\n", ps.optarg);
			break;
		case 'h':
            sprintf(output_text, "%s", help);
			return NULL;
			break;
		case 't':
			sprintf(output_text, "option --terms with argument '%s'\n", ps.optarg);
			break;
        case 'i':
			sprintf(output_text, "option --iterations with argument '%s'\n", ps.optarg);
			break;
		case '?':
		case ':':
            switch (ps.optopt)
            {
                case 't':
                    sprintf(output_text, "option --terms requires an argument. Example: --terms=10\n");
                    break;

                case 'i':
                    sprintf(output_text, "option --iterations requires an argument. Example: --iterations=3\n");
                    break;

                default:
                    sprintf(output_text, "unknown option %c\n", ps.optopt);
                    break;
            }
            cmd_args->success = 0;
            return output_text;
		default:
			sprintf(output_text, "error: unhandled option -%c\n", c);
			cmd_args->success = 0;
            return output_text;
			break;
		}
	}

    if (argc == 1)
    {
        // No options supplied
        sprintf(output_text, "%s", help);
    }

    cmd_args->success = 1;
    return output_text;
}