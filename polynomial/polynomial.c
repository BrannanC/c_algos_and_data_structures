#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term
{
    int coeff;
    int exp;
};

struct Polynomial
{
    int n;
    struct Term *t;
};

struct Polynomial *create(int n, int *coeffs, int *exps)
{
    struct Polynomial *new_p = (struct Polynomial *)malloc(sizeof(struct Polynomial *));
    new_p->t = (struct Term *)malloc(sizeof(struct Term *) * n);
    new_p->n = n;
    new_p->t = (struct Term *)malloc(new_p->n * sizeof(struct Term *));
    for (int i = 0; i < n; i++)
    {
        new_p->t[i].coeff = coeffs[i];
        new_p->t[i].exp = exps[i];
    }
    return new_p;
}

void display(struct Polynomial *p)
{
    for (int i = 0; i < p->n; i++)
    {
        printf("%dx^%d ", p->t[i].coeff, p->t[i].exp);
    }
    printf("\n");
}

int evaluate_polynomial(struct Polynomial *poly, int x)
{
    int total = 0;
    for (int i = 0; i < poly->n; i++)
    {
        total += poly->t[i].coeff * pow(x, poly->t->exp);
    }
    return total;
}

struct Polynomial *add_polynomials(struct Polynomial *a, struct Polynomial *b)
{
    int i, j, k;
    k = i = j = 0;
    struct Polynomial *sum = (struct Polynomial *)malloc(sizeof(struct Polynomial *));
    sum->t = (struct Term *)malloc(sizeof(struct Term *) * (a->n + b->n));
    while (i < a->n && j < b->n)
    {
        if (a->t[i].exp > b->t[j].exp)
        {
            sum->t[k++] = a->t[i++];
        }
        else if (a->t[i].exp < b->t[j].exp)
        {
            sum->t[k++] = b->t[j++];
        }
        else
        {
            sum->t[k].exp = a->t[i].exp;
            sum->t[k++].coeff = a->t[i++].coeff + b->t[j++].coeff;
        }
    }
    for (; i < a->n; i++)
        sum->t[k++] = a->t[i];
    for (; i < b->n; j++)
        sum->t[k++] = b->t[j];
    sum->n = k;
    return sum;
}

int main()
{
    int c[] = {1, 2, 3, 4};
    int e[] = {4, 3, 2, 1};
    int c2[] = {2, 3, 4, 5};
    int e2[] = {5, 4, 3, 2};

    struct Polynomial *p = create(4, c, e);
    display(p);
    struct Polynomial *p2 = create(4, c2, e2);
    display(p2);
    struct Polynomial *s = add_polynomials(p, p2);
    display(s);
    s = add_polynomials(s, p);
    display(s);

    return 0;
}