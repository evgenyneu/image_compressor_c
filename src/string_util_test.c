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

char *load_all_string_util_tests(void)
{
    MU_RUN_TEST(test_string_ends_with);
    return 0;
}