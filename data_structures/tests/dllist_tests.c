#include "minunit.h"
#include <lcthw/dllist/dllist.h>
#include <assert.h>

static DLList *list = NULL;
static DLList *right = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test_create()
{
    list = DLList_create();
    mu_assert(list != NULL, "Failed to create list.");

    return NULL;
}

char *test_destroy()
{
    DLList_clear_destroy(list);
    return NULL;
}

char *test_push_pop()
{
    DLList_push(list, test1);
    mu_assert(DLList_last(list) == test1, "Failed push test 1.");

    DLList_push(list, test2);
    mu_assert(DLList_last(list) == test2, "Failed push test 2");

    DLList_push(list, test3);
    mu_assert(DLList_last(list) == test3, "Failed push test 3");
    mu_assert(DLList_count(list) == 3, "Wrong count on push.");

    char *val = DLList_pop(list);
    mu_assert(val == test3, "Wrong value on pop.");

    val = DLList_pop(list);
    mu_assert(val == test2, "Wrong value on pop.");

    val = DLList_pop(list);
    mu_assert(val == test1, "Wrong value on pop.");
    mu_assert(DLList_count(list) == 0, "Wrong count on pop.");

    return NULL;
}

char *test_unshift()
{
    DLList_unshift(list, test1);
    mu_assert(DLList_first(list) == test1, "Wrong value on unshift.")

        DLList_unshift(list, test2);
    mu_assert(DLList_first(list) == test2, "Wrong value on unshift.")

        DLList_unshift(list, test3);
    mu_assert(DLList_first(list) == test3, "Wrong value on unshift.")
        mu_assert(DLList_count(list) == 3, "Wrong count on unshift.");

    return NULL;
}

char *test_swap()
{
    DLList_swap(list->first, list->last);
    mu_assert(list->first->value == test1, "Failed swap.");
    DLList_swap(list->first, list->last);
    mu_assert(list->first->value == test3, "Failed swap.");
    return NULL;
}

char *test_remove()
{
    char *val = DLList_remove(list, list->first->next);
    mu_assert(val == test2, "Wrong removed element.");
    mu_assert(DLList_count(list) == 2, "Wrong count after remove.");
    mu_assert(DLList_first(list) == test3, "Wrong first after remove.");
    mu_assert(DLList_last(list) == test1, "Wrong last after remove.");

    return NULL;
}

char *test_shift()
{
    mu_assert(DLList_count(list) != 0, "Wrong count before shift.");
    char *val = DLList_shift(list);
    mu_assert(val == test3, "Wrong value on shift.");

    val = DLList_shift(list);
    mu_assert(val == test1, "Wrong value on shift.");
    mu_assert(DLList_count(list) == 0, "Wrong count after shift.");

    return NULL;
}

char *test_split()
{
    right = DLList_split(list, 1);
    mu_assert(list->count == 1, "Failed split.");
    mu_assert(right->count == 2, "Failed split.");
    return NULL;
}

char *test_join()
{
    list = DLList_join(list, right);
    mu_assert(list->count == 3, "Failed join.");
    return NULL;
}

char *all_tests()
{
    mu_suite_start();
    mu_run_test(test_create);
    mu_run_test(test_push_pop);
    mu_run_test(test_unshift);
    mu_run_test(test_swap);
    mu_run_test(test_split);
    mu_run_test(test_join);
    mu_run_test(test_remove);
    mu_run_test(test_shift);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
