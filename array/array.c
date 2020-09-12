#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }

    return max;
}

int Sum(struct Array arr)
{
    int total = 0, i;

    for (i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }

    return total;
}

double Avg(struct Array arr)
{
    return (float)Sum(arr) / arr.length;
}

int BinSearch(struct Array arr, int key)
{
    int mid, l = 0, h = arr.length;
    while (l < h)
    {
        mid = floor(l + h);
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void Reverse(struct Array *arr)
{
    int i, tmp;
    for (i = 0; i < (arr->length - 1) / 2; i++)
    {
        swap(&arr->A[i], &arr->A[arr->length - i - 1]);
    }
}

int main()
{
    struct Array arr = {{1, 2, 11, 3, 10}, 5, 5};

    printf("%f \n", Avg(arr));
    printf("%d \n", Max(arr));
    Display(arr);
    Reverse(&arr);
    Display(arr);
    return 0;
}