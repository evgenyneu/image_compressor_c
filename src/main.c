#include <stdio.h>
#include <stdlib.h>

#include "load_image.h"

int main(int argc, char *argv[])
{
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