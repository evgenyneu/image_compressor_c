#include <stdio.h>
#include <stdlib.h>

#include "external/parg.h"
#include "load_image.h"

int main(int argc, char *argv[])
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
			printf("nonoption '%s'\n", ps.optarg);
			break;
		case 'h':
			printf("%s", help);
			return EXIT_SUCCESS;
			break;
		case 't':
			printf("option --terms with argument '%s'\n", ps.optarg);
			break;
        case 'i':
			printf("option --iterations with argument '%s'\n", ps.optarg);
			break;
		case '?':
		case ':':
            switch (ps.optopt)
            {
                case 't':
                    printf("option --terms requires an argument. Example: --terms=10\n");
                    break;

                case 'i':
                    printf("option --iterations requires an argument. Example: --iterations=3\n");
                    break;

                default:
                    printf("unknown option \n");
                    printf("unknown option %c\n", ps.optopt);
                    printf("optind %d\n", ps.optind);
                    printf("unknown option %s\n", ps.optarg);
                    break;
            }
            return EXIT_FAILURE;
		default:
			printf("error: unhandled option -%c\n", c);
			return EXIT_FAILURE;
			break;
		}
	}

    if (argc == 1)
    {
        // No options supplied
        printf("%s", help);
	    return EXIT_SUCCESS;
    }

    // while ((c = parg_getopt(&ps, argc, argv, "hs:v")) != -1) {
	// 	switch (c) {
	// 	case 1:
	// 		printf("nonoption '%s'\n", ps.optarg);
	// 		break;
	// 	case 'h':
	// 		printf("Usage: compressor [-h] [-v] [-s STRING]\n");
	// 		return EXIT_SUCCESS;
	// 		break;
	// 	case 's':
	// 		printf("option -s with argument '%s'\n", ps.optarg);
	// 		break;
	// 	case 'v':
	// 		printf("compressor 1.0.0\n");
	// 		return EXIT_SUCCESS;
	// 		break;
	// 	case '?':
	// 		if (ps.optopt == 's') {
	// 			printf("option -s requires an argument\n");
	// 		}
	// 		else {
	// 			printf("unknown option -%c\n", ps.optopt);
	// 		}
	// 		return EXIT_FAILURE;
	// 		break;
	// 	default:
	// 		printf("error: unhandled option -%c\n", c);
	// 		return EXIT_FAILURE;
	// 		break;
	// 	}
	// }

	// for (c = ps.optind; c < argc; ++c) {
	// 	printf("nonoption '%s'\n", argv[c]);
	// }

	return EXIT_SUCCESS;
}