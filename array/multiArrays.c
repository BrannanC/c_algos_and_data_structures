#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *lcs(char *s, char *t)
{
    int l1 = strlen(s), l2 = strlen(t), i, j, m = 0, ind = 0;
    int g[l1][l2];

    for (i = 0; i < l1; i++)
    {
        for (j = 0; j < l2; j++)
        {
            if (s[i] == t[j])
            {
                if (i == 0 || j == 0)
                {
                    g[i][j] = 1;
                }
                else
                {
                    g[i][j] = g[i - 1][j - 1] + 1;
                }
            }
            else
            {
                g[i][j] = 0;
            }
            if (g[i][j] > m)
            {
                m = g[i][j];
                ind = j;
            }
        }
    }

    int *res = (int *)malloc(2 * sizeof(int));
    res[0] = ind;
    res[1] = m;
    return res;
}

int main()
{
    char *s = "aaaaaaaaaaaaaxoxoaaaaaaaaa";
    char *t = "absdabsmdafkfogofjfxofkfkfkfkfkfxoxoxoxoxdkdkdkdkdkdkdkd";
    int *substr = lcs(s, t);
    int i = substr[0] - substr[1] + 1;

    printf("Longest substring length: %d \n", substr[1]);
    for (; i <= substr[0]; i++)
    {
        printf("%c", t[i]);
    }
    printf("\n");
    return 0;
}