#include <stdio.h>
#include <lcthw/dllist/dllist.h>
#include <lcthw/dllist/dllist_algos.h>

int DLList_bubble_sort(DLList *list, DLList_compare cmp)
{
    if (list->count <= 1)
        return 0;
    int sorted = 0;
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
    if (list->count <= 1)
        return list;
    DLList *right = DLList_split(list, list->count >> 1);
    return DLList_merge(DLList_merge_sort(list, cmp), DLList_merge_sort(right, cmp), cmp);
}

DLList *DLList_merge(DLList *left, DLList *right, DLList_compare cmp)
{
    DLList *res = DLList_create();
    while (left->count && right->count)
    {
        if (cmp(left->first->value, right->first->value) > 0)
        {
            DLList_push(res, DLList_shift(right));
        }
        else
        {
            DLList_push(res, DLList_shift(left));
        }
    }

    while (left->count)
    {
        DLList_push(res, DLList_shift(left));
    }

    while (right->count)
    {
        DLList_push(res, DLList_shift(right));
    }

    return res;
}