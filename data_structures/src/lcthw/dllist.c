#include <lcthw/dllist.h>
#include <lcthw/dbg.h>

DLList *DLList_create()
{
    return calloc(1, sizeof(DLList));
}

void DLList_destroy(DLList *list)
{
    DLLIST_FOREACH(list, first, next, cur)
    {
        if (cur->prev)
        {
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}

void DLList_clear(DLList *list)
{
    DLLIST_FOREACH(list, first, next, cur)
    {
        free(cur->value);
    }
}

void DLList_clear_destroy(DLList *list)
{
    printf("\n---start\n");
    DLList_clear(list);
    printf("cleared\n");
    DLList_destroy(list);
    printf("destroyed\n");
}

void DLList_push(DLList *list, void *value)
{
    DLListNode *node = calloc(1, sizeof(DLListNode));
    check_mem(node);

    node->value = value;

    if (list->last == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    list->count++;

error:
    return;
}

void *DLList_pop(DLList *list)
{
    DLListNode *node = list->last;
    return node != NULL ? DLList_remove(list, node) : NULL;
}

void DLList_unshift(DLList *list, void *value)
{
    DLListNode *node = calloc(1, sizeof(DLListNode));
    check_mem(node);

    node->value = value;

    if (list->first == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }

    list->count++;

error:
    return;
}

void *DLList_shift(DLList *list)
{
    DLListNode *node = list->first;
    return node != NULL ? DLList_remove(list, node) : NULL;
}

void *DLList_remove(DLList *list, DLListNode *node)
{
    void *res = NULL;
    check(list->first && list->last, "Empty List.");
    check(node, "Node can't be null.");

    if (node == list->first && node == list->last)
    {
        list->first = NULL;
        list->last = NULL;
    }
    else if (node == list->first)
    {
        list->first = node->next;
        check(list->first != NULL, "Invalid list, first is NULL.");
        list->first->prev = NULL;
    }
    else if (node == list->last)
    {
        list->last = node->prev;
        check(list->last != NULL, "Invalid list.");
        list->last->next = NULL;
    }
    else
    {
        DLListNode *after = node->next;
        DLListNode *before = node->prev;
        after->prev = before;
        before->next = after;
    }

    list->count--;
    res = node->value;
    free(node);
    return res;
error:
    return res;
}

void DLList_swap(DLListNode *lhs, DLListNode *rhs)
{
    void *tmp = lhs->value;
    lhs->value = rhs->value;
    rhs->value = tmp;
}

DLList *DLList_copy(DLList *list)
{
    DLList *clone = DLList_create();

    DLLIST_FOREACH(list, first, next, cur)
    {
        DLList_unshift(clone, cur->value);
    }

    return clone;
}

DLList *DLList_join(DLList *a, DLList *b)
{
    DLList *joined = DLList_copy(a);
    DLLIST_FOREACH(b, first, next, cur)
    {
        DLList_push(joined, cur->value);
    }

    return joined;
}

/* DLList_split truncates the original list and returns the truncated items
as another list */
DLList *DLList_split(DLList *list, int index)
{
    if (index >= list->count - 1)
        return NULL;
    DLList *right = DLList_create();
    while (list->count >= index)
    {
        DLList_unshift(right, DLList_pop(list));
    }

    return right;
}
