#include <stdio.h>
#include <stdlib.h>
#include "annotate.h"
#include "string_util.h"

void annotate(const char *path, int terms, double compression, int width)
{
    char *terms_word;

    if (terms == 1)
    {
        terms_word = copy_string("term");
    }
    else
    {
        terms_word = copy_string("terms");
    }

    char *message = malloc(1000 * sizeof(char));
    sprintf(message, "%d %s\n%.1fx compression", terms, terms_word, compression);
    int fontsize = calculate_font_size(width);
    int margin = fontsize;

    char *annotation = malloc(10000 * sizeof(char));
    sprintf(annotation, "-pointsize %d -gravity south -stroke '#000C' "
        "-strokewidth 2 -annotate +0+%d '%s' "
        "-stroke none -fill white -annotate +0+%d '%s'",
        fontsize,  margin, message, margin, message);


    char *command = malloc(10000 * sizeof(char));

    sprintf(command, "convert '%s' %s '%s'", path, annotation, path);

    if (system(command) != 0)
    {
        printf("Could not call `convert` program to annotate the image. Please install Image Magic if you need annotations.\n");
    }

    // Free memory
    free(terms_word);
    free(message);
    free(annotation);
    free(command);
}

int calculate_font_size(int width)
{
    int fontsize;

    if (width < 200)
    {
        fontsize = (int)((double) width / 10);
    }
    else if (width < 800)
    {
        fontsize = (int)((double) width / 15);
    }
    else
    {
        fontsize = (int)((double) width / 20);
    }

    return fontsize;
}