#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
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
    char *result = malloc((str_len + 1) * sizeof(char));

    if (result == NULL)
    {
        perror("Can not allocate memory for string.");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < str_len; i++)
    {
        result[i] = (char) tolower(string[i]);
    }
    
    result[str_len] = '\0';

    return result;
}


int string_to_int(const char *string, int *number)
{
    char *end;
    long result = strtol(string, &end, 10);

    if (errno == ERANGE)
    {
        return 1;
    }

    if (result > INT_MAX || result < INT_MIN)
    {
        return 1;
    }

    if (strcmp(end, string) == 0)
    {
        // string is empty or is not a number
        return 1;
    }

    *number = (int) result;
    return 0;
}


char *copy_string(const char *string)
{
    char *new_string = malloc(strlen(string) + 1); 
    strcpy(new_string, string);
    return new_string;
}