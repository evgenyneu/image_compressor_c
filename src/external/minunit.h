#ifndef INCLUDE_MINUNIT_H
#define INCLUDE_MINUNIT_H

/*
Unit testing helper.
Based on http://www.jera.com/techinfo/jtns/jtn002.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Fail if `test` is false
#define MU_ASSERT(test) do { \
    if (!(test)) { \
        char *buffer; \
        buffer = malloc(1024 * sizeof(char)); \
        sprintf(buffer, "\nTEST FAILED: %s:%d %s\n", __FILE__, __LINE__, __FUNCTION__); \
        return buffer; } \
    } while (0)

// Fail if two values are not equal
#define MU_EQUAL_DOUBLE(a, b) do { \
    if (a != b) { \
        char *buffer; \
        buffer = malloc(1024 * sizeof(char)); \
        sprintf(buffer, "\nTEST FAILED: %f != %f, %s:%d %s\n", a, b, __FILE__, __LINE__, __FUNCTION__); \
        return buffer; } \
    } while (0)


// Fail if the absolute difference between two values `a` and `b` is greater than `diff`
#define MU_APPROX_DOUBLE(a, b, diff) do { \
    if (fabs(a - b) > diff) { \
        char *buffer; \
        buffer = malloc(1024 * sizeof(char)); \
        sprintf(buffer, "\nTEST FAILED: %.14f != %.14f, %s:%d %s\n", a, b, __FILE__, __LINE__, __FUNCTION__); \
        return buffer; } \
    } while (0)


// Fail if two values are not equal
#define MU_EQUAL_INT(a, b) do { \
    if (a != b) { \
        char *buffer; \
        buffer = malloc(1024 * sizeof(char)); \
        sprintf(buffer, "\nTEST FAILED: %d != %d, %s:%d %s\n", a, b, __FILE__, __LINE__, __FUNCTION__); \
        return buffer; } \
    } while (0)

// Fail if strings are not equal
#define MU_EQUAL_STR(a, b) do { \
    if (a == NULL || b == NULL) { \
        char *buffer; \
        buffer = malloc(1024 * sizeof(char)); \
        sprintf(buffer, "\nTEST FAILED: NULL string, %s:%d %s\n", __FILE__, __LINE__, __FUNCTION__); \
        return buffer; \
    } else if (strcmp(a, b) != 0) { \
        char *buffer; \
        buffer = malloc(1024 * sizeof(char)); \
        sprintf(buffer, "\nTEST FAILED: %s != %s, %s:%d %s\n", a, b, __FILE__, __LINE__, __FUNCTION__); \
        return buffer; } \
    } while (0)

#define MU_RUN_TEST(test) do { printf("."); char *message = test(); tests_run++; \
                            if (message) return message; } while (0)
extern int tests_run;

#endif // INCLUDE_MINUNIT_H