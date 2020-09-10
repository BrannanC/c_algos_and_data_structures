#include <stdio.h>

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int comb(int n, int r)
{
    int num, den;

    num = fact(n);
    den = fact(r) * fact(n - r);

    return num / den;
}

int combRec(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return combRec(n - 1, r - 1) + combRec(n - 1, r);
}

int main()
{
    printf("%d \n", comb(4, 2));
    printf("%d \n", combRec(4, 2));
    return 0;
}