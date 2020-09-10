#include <stdio.h>

int fib(int n)
{
    int n1 = 1, n2 = 0, t = 0, i;

    if (n < 2)
        return n;

    for (i = 2; i <= n; i++)
    {
        t = n1 + n2;
        n2 = n1;
        n1 = t;
    }
    return t;
}

int rfib(int n)
{
    if (n <= 1)
        return n;
    return rfib(n - 1) + rfib(n - 2);
}

int mfib_calc(int n, int *M)
{
    if (n < 2)
    {
        M[n] = n;
        return n;
    }
    else
    {
        if (M[n - 2] == -1)
            M[n - 2] = mfib_calc(n - 2, M);
        if (M[n - 1] == -1)
            M[n - 1] = mfib_calc(n - 1, M);
        return M[n - 2] + M[n - 1];
    }
}

int mfib(int n)
{
    if (n < 2)
        return n;
    int M[n];
    int i;
    for (i = 0; i < 10; i++)
    {
        M[i] = -1;
    }

    return mfib_calc(n, M);
}

int main()
{
    printf("%d \n", fib(10));
    printf("%d \n", rfib(10));
    printf("%d \n", mfib(10));
    return 0;
}