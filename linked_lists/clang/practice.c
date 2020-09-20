#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * first;

void create(int arr[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

void RDisplay(struct Node *p)
{
    if (p)
    {
        RDisplay(p->next);
        printf("%d ", p->data);
    }
    if (p == first)
    {
        printf("\n");
    }
}

int sum(struct Node *p)
{
    int t = 0;
    while (p)
    {
        t += p->data;
        p = p->next;
    }

    return t;
}

int max(struct Node *p)
{
    int m = -32768;
    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

void move_to_head(struct Node *p, int val)
{
    struct Node *prev = NULL;
    while (p)
    {
        if (p->data == val)
        {
            if (prev)
            {
                prev->next = p->next;
                p->next = first;
                first = p;
                return;
            }
        }
        prev = p;
        p = p->next;
    }
}

int main()
{
    int arr[] = {3, 5, 7, 10, 15};
    create(arr, 5);
    Display(first);
    RDisplay(first);
    printf("%d \n", count(first));
    printf("%d \n", sum(first));
    printf("%d \n", max(first));
    move_to_head(first, 7);
    Display(first);
    return 0;
}