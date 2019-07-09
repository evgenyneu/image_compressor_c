#include "external/minunit.h"
#include "string_util.h"
#include "string_util_test.h"

static char *test_string_ends_with()
{
    MU_EQUAL_INT(string_ends_with("My long string", "string"), 1);
    MU_EQUAL_INT(string_ends_with("My long string.", "string"), 0);
    MU_EQUAL_INT(string_ends_with("My", "string"), 0);
    MU_EQUAL_INT(string_ends_with("", ""), 1);
    MU_EQUAL_INT(string_ends_with("", "1"), 0);
    MU_EQUAL_INT(string_ends_with("string", ""), 1);
    return 0;
}


static char *test_string_to_lower()
{
    MU_EQUAL_STR(string_to_lower("My String"), "my string");

    return 0;
}


static char *test_string_to_int()
{
    int number;
    int result;

    result = string_to_int("123", &number);
    MU_EQUAL_INT(number, 123);
    MU_EQUAL_INT(result, 0);

    // Ignore spaces
    result = string_to_int(" 123 ", &number);
    MU_EQUAL_INT(number, 123);
    MU_EQUAL_INT(result, 0);

    // Negative
    result = string_to_int("-4", &number);
    MU_EQUAL_INT(number, -4);
    MU_EQUAL_INT(result, 0);

    // Float
    result = string_to_int("12.1232", &number);
    MU_EQUAL_INT(number, 12);
    MU_EQUAL_INT(result, 0);

    // Zero
    result = string_to_int("0", &number);
    MU_EQUAL_INT(number, 0);
    MU_EQUAL_INT(result, 0);

    // ERROR: greater than max integer
    result = string_to_int("2147483648", &number);
    MU_EQUAL_INT(result, 1);

    // ERROR: Smaller than min integer
    result = string_to_int("-2147483649", &number);
    MU_EQUAL_INT(result, 1);

    // ERROR: Non-integer
    result = string_to_int("junk", &number);
    MU_EQUAL_INT(result, 1);

    // ERROR: empty
    result = string_to_int("", &number);
    MU_EQUAL_INT(result, 1);

    // ERROR: blank
    result = string_to_int(" ", &number);
    MU_EQUAL_INT(result, 1);

    return 0;
}

char *load_all_string_util_tests(void)
{
    MU_RUN_TEST(test_string_ends_with);
    MU_RUN_TEST(test_string_to_lower);
    MU_RUN_TEST(test_string_to_int);
    return 0;
}