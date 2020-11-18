#ifndef lcthw_dllist_h
#define lcthw_dllist_h

#include <stdlib.h>

struct DLListNode;
typedef struct DLListNode
{
    struct DLListNode *next;
    struct DLListNode *prev;
    void *value;
} DLListNode;

typedef struct DLList
{
    int count;
    DLListNode *first;
    DLListNode *last;
} DLList;

DLList *DLList_create();
void DLList_destroy(DLList *list);
void DLList_clear(DLList *list);
void DLList_clear_destroy(DLList *list);

#define DLList_count(A) ((A)->count)
#define DLList_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
#define DLList_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

void DLList_push(DLList *list, void *value);
void *DLList_pop(DLList *list);
void DLList_unshift(DLList *list, void *value);
void *DLList_shift(DLList *list);

void *DLList_remove(DLList *list, DLListNode *node);

#define DLLIST_FOREACH(L, S, M, V) \
    DLListNode *_node = NULL;      \
    DLListNode *V = NULL;          \
    for (V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif