/*
Calculate the dominant eigenvalue and eigenvector of a matrix using the power method.
*/


#ifndef INCLUDE_STRING_UTIL_H
#define INCLUDE_STRING_UTIL_H

#include "linear_algebra.h"

/*

Check if `target` string ends with `ending`.

Inputs:
-------

target : a target string

ending : a substring to be located in  `target`


Outputs:
-------

Returns : 1 if `ending` is found at the end of `target`. Returns 0 otherwise.

*/
int string_ends_with(const char *target, const char *ending);

#endif // INCLUDE_STRING_UTIL_H