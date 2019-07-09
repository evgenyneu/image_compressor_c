/*
Calculate the dominant eigenvalue and eigenvector of a matrix using the power method.
*/


#ifndef INCLUDE_STRING_UTIL_H
#define INCLUDE_STRING_UTIL_H

#include "linear_algebra.h"

/*

Check if `target` string ends with `ending`.

Based on https://codereview.stackexchange.com/a/54726

Inputs:
-------

target : a target string

ending : a substring to be located in  `target`


Outputs:
-------

Returns : 1 if `ending` is found at the end of `target`. Returns 0 otherwise.

*/
int string_ends_with(const char *target, const char *ending);

/*

Converts string to lower case

Inputs:
-------

string : string to convert to lower case.


Outputs:
-------

Returns : a lowercase string.

*/
char *string_to_lower(const char *string);


/*

Converts string to integer.

Inputs:
-------

string : string to convert to integer.


Outputs:
-------

number : the number parsed from `string`.

Returns : 0 on success, 1 on error.

*/
int string_to_int(const char *string, int *number);

#endif // INCLUDE_STRING_UTIL_H