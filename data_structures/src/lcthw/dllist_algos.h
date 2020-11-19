#ifndef lcthw_DLList_algos_h
#define lcthw_DLList_algos_h

#include <lcthw/dllist.h>

typedef int (*DLList_compare)(const void *a, const void *b);

int DLList_bubble_sort(DLList *list, DLList_compare cmp);

DLList *DLList_merge_sort(DLList *list, DLList_compare cmp);

#endif