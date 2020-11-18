#include <lcthw/dbllist.h>
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
    DLList_clear(list);
    DLList_destroy(list);
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
        check(list->last != NULL, "Ivalid list.");
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
