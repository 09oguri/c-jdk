#include <stdio.h>

#include "minunit.h"
#include "util.ArrayList.h"

#define ERR_MSG_LENGTH 512

char err_msg[ERR_MSG_LENGTH] = {};
int tests_run = 0;
int tests = 0;

static char * test_add() {
    char* test_name = "test_add";

    ArrayList_t list = ArrayList(100);
    char* expected = "hello, world";
    list.add(&list, 0, "hello, world");
    char* actual = list.get(&list, 0);

    sprintf(err_msg, "[FAILD] %s\n\texpected<%s> but actual <%s>", test_name, expected, actual);
    mu_assert(err_msg, actual == expected);

    //list.del(&list);
    printf("[SUCCESS] %s\n", test_name);
    return 0;
}

static char * test_init() {
    char* test_name = "test_init";

    ArrayList_t list1 = ArrayList(100);
    ArrayList_t list2 = ArrayList(100);
    list1.add(&list1, 0, "hello, world0");
    list1.add(&list1, 1, "hello, world1");
    list1.add(&list1, 2, "hello, world2");
    list2.add(&list2, 0, "hello, world3");
    list2.add(&list2, 1, "hello, world4");
    list2.add(&list2, 2, "hello, world5");

    char* expected = "hello, world0";
    char* actual = list1.get(&list1, 0);

    sprintf(err_msg, "[FAILD] %s\n\texpected<%d> but actual <%d>", test_name, expected, actual);
    mu_assert(err_msg, actual == expected);

    //list.del(&list);
    printf("[SUCCESS] %s\n", test_name);
    return 0;
}

static char * test_size() {
    char* test_name = "test_size";

    ArrayList_t list = ArrayList(100);
    int expected = 3;
    list.add(&list, 0, "hello, world");
    list.add(&list, 1, "hello, world");
    list.add(&list, 2, "hello, world");
    int actual = list.size(&list);

    sprintf(err_msg, "[FAILD] %s\n\texpected<%d> but actual <%d>", test_name, expected, actual);
    mu_assert(err_msg, actual == expected);

    //list.del(&list);
    printf("[SUCCESS] %s\n", test_name);
    return 0;
}

static char * all_tests() {
    tests = 3;
    mu_run_test(test_add);
    mu_run_test(test_init);
    mu_run_test(test_size);
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
