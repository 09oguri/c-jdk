#include <stdio.h>

#include "minunit.h"
#include "string.h"

#define ERR_MSG_LENGTH 512

char err_msg[ERR_MSG_LENGTH] = {};
int tests_run = 0;
int tests = 0;

static char * test_charAt() {
    char* test_name = "test_charAt";

    String_t *s = String("hello, world");
    char expected = 'o';
    char actual = s->charAt(s, 4);

    sprintf(err_msg, "[FAILD] %s\n\texpected<%c> but actual <%c>", test_name, expected, actual);
    mu_assert(err_msg, actual == expected);

    s->del(s);
    printf("[SUCCESS] %s\n", test_name);
    return 0;
}

static char * test_length() {
    char* test_name = "test_length";

    String_t *s = String("hello, world");
    int expected = 12;
    int actual = s->length(s);

    sprintf(err_msg, "[FAILD] %s\n\texpected<%d> but actual <%d>", test_name, expected, actual);
    mu_assert(err_msg, actual == expected);

    s->del(s);
    printf("[SUCCESS] %s\n", test_name);
    return 0;
}

static char * test_replace() {
    char* test_name = "test_replace";

    String_t *s1 = String("hello, world");
    String_t *s2 = s1->replace(s1, 'o', '?');
    int expected = 12;
    int actual = s2->length(s2);

    sprintf(err_msg, "[FAILD] %s\n\texpected<%d> but actual <%d>", test_name, expected, actual);
    mu_assert(err_msg, actual == expected);

    s1->del(s1);
    s2->del(s2);
    printf("[SUCCESS] %s\n", test_name);
    return 0;
}

static char * all_tests() {
    tests = 3;
    mu_run_test(test_charAt);
    mu_run_test(test_length);
    mu_run_test(test_replace);
    return 0;
}

int main(int argc, char **argv) {
    printf("\n########## Unit Test ##########\n");

    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
        printf("\nTESTS FAILD\n");
    } else {
        printf("\nALL TESTS PASSED\n");
    }

    printf("Tests run: %d / %d\n", tests_run, tests);
    printf("#############################\n");

    return result != 0;
}
