#include <string.h>
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