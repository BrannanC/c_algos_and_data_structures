#include <stdio.h>
#include <lcthw/dllist.h>
#include <lcthw/dllist_algos.h>

int DLList_bubble_sort(DLList *list, DLList_compare cmp)
{
    if (list->count <= 1)
        return 0;
    int sorted = 0;
    DLListNode *cur = list->first;
    while (!sorted)
    {
        sorted = 1;
        DLLIST_FOREACH(list, first, next, cur)
        {
            if (cur->prev)
            {
                if (cmp(cur->prev->value, cur->value) > 0)
                {
                    DLList_swap(cur->prev, cur);
                    sorted = 0;
                }
            }
        }
    }

    return 0;
}

DLList *DLList_merge_sort(DLList *list, DLList_compare cmp)
{
    return list;
}