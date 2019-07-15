#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "external/parg.h"
#include "cmd_args.h"
#include "string_util.h"


CmdArgs *new_cmd_args(void)
{
    CmdArgs *cmd_args = malloc(sizeof(CmdArgs));
    cmd_args->path = NULL;
    cmd_args->output = NULL;
    cmd_args->terms = 10;
    cmd_args->iterations = 3;
    cmd_args->benchmark = 0;
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
    int number;

    const struct parg_option po_def[] = {
        { "terms", PARG_REQARG, NULL, 't' },
        { "iterations", PARG_REQARG, NULL, 'i' },
        { "help", PARG_NOARG, NULL, 'h' },
        { "benchmark", PARG_NOARG, NULL, 'b' },
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
        "--benchmark :  run the benchmark to measure compression performance,\n"
        "               no other options are needed for the benchmark\n"
        "--help :  show this message\n";

	while ((c = parg_getopt_long(&ps,  argc, argv, "ma", po_def, &li)) != -1) {
		switch (c) {
		case 1: // Non-optional argument (i.e. without the leading `--`)
            if (cmd_args->path == NULL) {
                cmd_args->path = copy_string(ps.optarg);
            }
            else if (cmd_args->output == NULL)
            {
                cmd_args->output = copy_string(ps.optarg); 
            }
            else
            {
                sprintf(buffer, "ERROR: unkown option '%s'\n", ps.optarg);
                strcat(output_text, buffer);
                cmd_args->ready_to_compress = 0;
                return output_text;
            }
			break;
		case 'h': // --help
            sprintf(buffer, "%s", help);
            strcat(output_text, buffer);
            cmd_args->ready_to_compress = 0;
			return output_text;
			break;
        case 'b': // --benchmark
            benchmark_options(cmd_args);
			return output_text;
			break;
		case 't': // --terms
            if (string_to_int(ps.optarg, &number) == 0)
            {
                cmd_args->terms = number;
            }
            else
            {
                sprintf(buffer, "ERROR: --terms value is not a number.\n");
                strcat(output_text, buffer);
                cmd_args->ready_to_compress = 0;
                return output_text;
            }
			break;
        case 'i': // --iterations
			if (string_to_int(ps.optarg, &number) == 0)
            {
                cmd_args->iterations = number;
            }
            else
            {
                sprintf(buffer, "ERROR: --iterations value is not a number.\n");
                strcat(output_text, buffer);
                cmd_args->ready_to_compress = 0;
                return output_text;
            }
			break;
		case '?': // Missing required argument or incorrect option
		case ':':
            switch (ps.optopt)
            {
                case 't':
                    sprintf(buffer, "ERROR: option --terms requires an argument. Example: --terms=10\n");
                    strcat(output_text, buffer);
                    break;

                case 'i':
                    sprintf(buffer, "ERROR: option --iterations requires an argument. Example: --iterations=3\n");
                    strcat(output_text, buffer);
                    break;

                default:
                    sprintf(buffer, "ERROR: unknown option %c\n", ps.optopt);
                    strcat(output_text, buffer);
                    break;
            }
            cmd_args->ready_to_compress = 0;
            return output_text;
		default: // Unexpected option
			sprintf(buffer, "ERROR: unhandled option -%c\n", c);
            strcat(output_text, buffer);
			cmd_args->ready_to_compress = 0;
            return output_text;
			break;
		}
	}

    if (argc == 1)
    {
        // No options supplied
        strcat(output_text, help);
        cmd_args->ready_to_compress = 0;
        return output_text;
    }

    if (cmd_args->path == NULL)
    {
        sprintf(buffer, "ERROR: IMAGE path is not supplied\n");
        strcat(output_text, buffer);
        cmd_args->ready_to_compress = 0;
        return output_text; 
    }

    if (cmd_args->output == NULL)
    {
        sprintf(buffer, "ERROR: OUTPUT path is not supplied\n");
        strcat(output_text, buffer);
        cmd_args->ready_to_compress = 0;
        return output_text; 
    }

    cmd_args->ready_to_compress = 1;
    return output_text;
}


void benchmark_options(CmdArgs *cmd_args)
{
    cmd_args->ready_to_compress = 1;
    cmd_args->benchmark = 1;
    cmd_args->terms = 30;
    cmd_args->iterations = 5;
    cmd_args->path = copy_string("images/marmite_500x500.jpg");
    cmd_args->output = copy_string("images/marmite_output_500x500.bmp");
}