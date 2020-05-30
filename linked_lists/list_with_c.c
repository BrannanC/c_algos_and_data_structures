#include "list.c"

int main()
{
    struct List *l = malloc(sizeof(List));
    list_init(l, NULL);
    int arr[] = {0, 1, 2, 3, 4};
    int a = 0;
    while (a < 5)
    {
        void *vp = &(arr[a]);
        list_ins_next(l, NULL, vp);
        a++;
    }

    void *vp;

    ListElmt *curr = l->head;
    while (curr != NULL)
    {
        vp = list_data(curr);
        printf("%d\n", *(int *)vp);
        curr = curr->next;
    }
    void **rp = (void **)malloc(sizeof(void *));
    list_rem_next(l, NULL, rp);

    curr = l->head;
    while (curr != NULL)
    {
        vp = list_data(curr);
        printf("%d\n", *(int *)vp);
        curr = curr->next;
    }

    return 0;
}