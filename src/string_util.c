#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "string_util.h"

int string_ends_with(const char *target, const char *ending)
{
    int target_len = (int) strlen(target);
    int ending_len = (int) strlen(ending);
    if (target_len >= ending_len)
    {
        return (0 == memcmp(ending, target + (target_len - ending_len), (unsigned long) ending_len));
    }
    return 0; // t was longer than s
}

char *string_to_lower(const char *string)
{
    unsigned long str_len = strlen(string);
    unsigned long i;
    char *result = malloc(str_len * sizeof(char));

    if (result == NULL)
    {
        perror("Can not allocate memory for string.");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < str_len; i++)
    {
        result[i] = (char) tolower(string[i]);
    }

    return result;
}