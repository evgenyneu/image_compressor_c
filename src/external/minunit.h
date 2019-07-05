#ifndef INCLUDE_MINUNIT_H
#define INCLUDE_MINUNIT_H

/*
Unit testing helper.
Based on http://www.jera.com/techinfo/jtns/jtn002.html
*/

#include <stdio.h>
#include <stdlib.h>

#define mu_assert(test) do { \
    if (!(test)) { \
        char *buffer; \
        buffer = malloc(1024 * sizeof(char)); \
        sprintf(buffer, "\nTEST FAILED: %s:%d %s\n", __FILE__, __LINE__, __FUNCTION__); \
        return buffer; } \
    } while (0)

#define mu_equal_double(a, b) do { \
    if (a != b) { \
        char *buffer; \
        buffer = malloc(1024 * sizeof(char)); \
        sprintf(buffer, "\nTEST FAILED: %f != %f, %s:%d %s\n", a, b, __FILE__, __LINE__, __FUNCTION__); \
        return buffer; } \
    } while (0)

#define mu_run_test(test) do { char *message = test(); tests_run++; \
                            if (message) return message; } while (0)
extern int tests_run;

#endif // INCLUDE_MINUNIT_H