#include "minunit.h"
#include <lcthw/dllist_algos.h>
#include <assert.h>
#include <string.h>

char *values[] = {"XXXX", "1234", "abcd", "xjvef", "NDSS"};

#define NUM_VALUES 5

DLList *create_words()
{
    int i = 0;
    DLList *words = DLList_create();
    for (i = 0; i < NUM_VALUES; i++)
    {
        DLList_push(words, values[i]);
    }

    return words;
}

int is_sorted(DLList *words)
{
    DLLIST_FOREACH(words, first, next, cur)
    {
        if (cur->next && strcmp(cur->value, cur->next->value) > 0)
        {
            debug("%s %s", (char *)cur->value, (char *)cur->next->value);
            return 0;
        }
    }
    return 1;
}

char *test_bubble_sort()
{
    DLList *words = create_words();

    int rc = DLList_bubble_sort(words, (DLList_compare)strcmp);
    mu_assert(rc == 0, "Bubble sort failed.");
    mu_assert(is_sorted(words), "Not sorted after bubble sort.");

    DLList_destroy(words);

    words = DLList_create(words);
    rc = DLList_bubble_sort(words, (DLList_compare)strcmp);
    mu_assert(rc == 0, "Bubble sort failed empty list.");
    mu_assert(is_sorted(words), "Empty list should be sorted.");

    DLList_destroy(words);
    return NULL;
}

char *test_merge_sort()
{
    DLList *words = create_words();

    DLList *res = DLList_merge_sort(words, (DLList_compare)strcmp);
    mu_assert(is_sorted(res), "Not sorted after merge sort.");
    res = DLList_merge_sort(res, (DLList_compare)strcmp);
    mu_assert(is_sorted(res), "Should still be sorted after merge sort.");

    DLList_destroy(res);
    DLList_destroy(words);
    return NULL;
}

char *all_tests()
{
    mu_suite_start();
    mu_run_test(test_bubble_sort);
    mu_run_test(test_merge_sort);

    return NULL;
}

RUN_TESTS(all_tests);
