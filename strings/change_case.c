#include <stdio.h>
#include <string.h>

void apply_to_string(char *s, char (*fn)(char *))
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        (*fn)(&s[i]);
    }
}

void ch_swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void change_case(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] += 32;
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] -= 32;
        }
    }
}

void reverse(char s[])
{
    size_t sz = strlen(s);
    for (int i = 0; i < sz / 2; i++)
    {
        ch_swap(&s[i], &s[sz - i - 1]);
    }
}

char ch_lower(char *a)
{
    if (*a >= 65 && *a <= 90)
    {
        *a += 32;
    }
    return *a;
}

char ch_upper(char *a)
{
    if (*a >= 97 && *a <= 122)
    {
        *a -= 32;
    }
    return *a;
}
char ch_to_lower(char a)
{
    if (a >= 65 && a <= 90)
    {
        return a + 32;
    }
    return a;
}

void lower(char s[])
{
    apply_to_string(s, &ch_lower);
}

void upper(char s[])
{
    apply_to_string(s, &ch_upper);
}

void spongebob_case(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (i % 2)
            ch_upper(&s[i]);
        else
        {
            ch_lower(&s[i]);
        }
    }
}

int is_palindrome(char a[])
{
    size_t l = strlen(a);
    for (int i = 0; i < l / 2; i++)
    {
        if (ch_to_lower(a[i]) != ch_to_lower(a[l - 1 - i]))
            return 0;
    }
    return 1;
}

int has_dupe(char s[])
{
    long int h = 0, x = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        x = 1;
        x <<= ch_to_lower(s[i]) - 97;
        if ((x & h) > 0)
        {
            return 1;
        }
        h |= x;
    }
    return 0;
}

int is_anagram(char a[], char b[])
{
    int h[25] = {0};
    for (int i = 0; a[i] != '\0'; i++)
    {
        h[ch_to_lower(a[i]) - 97] += 1;
    }

    for (int i = 0; b[i] != '\0'; i++)
    {
        h[ch_to_lower(b[i]) - 97] -= 1;
        if (h[ch_to_lower(b[i]) - 97] < 0)
            return 0;
    }

    for (int i = 0; i < 25; i++)
    {
        if (h[i] != 0)
            return 0;
    }
    return 1;
}

void perms_helper(char *s, char res[], int a[], int k)
{
    if (s[k] == '\0')
    {
        res[k] = '\0';
        printf("%s \n", res);
    }
    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (a[i] == 0)
            {
                res[k] = s[i];
                a[i] = 1;
                perms_helper(s, res, a, k + 1);
                a[i] = 0;
            }
        }
    }
}

void print_perms(char *s)
{
    int l = strlen(s);
    int a[l];
    char res[l];
    for (int i = 0; s[i] != '\0'; i++)
    {
        a[i] = 0;
    }
    perms_helper(s, res, a, 0);
}

void better_helper(char s[], int l, int h)
{
    if (l == h)
        printf("%s \n", s);
    else
    {
        for (int i = l; i <= h; i++)
        {
            ch_swap(&s[l], &s[i]);
            better_helper(s, l + 1, h);
            ch_swap(&s[l], &s[i]);
        }
    }
}

void better_print_perms(char s[])
{
    better_helper(s, 0, strlen(s) - 1);
}

int main()
{
    char word_dog[] = "*** SPONGEBOB ***";

    printf("%s \n", word_dog);
    lower(word_dog);
    printf("%s \n", word_dog);
    upper(word_dog);
    printf("%s \n", word_dog);
    spongebob_case(word_dog);
    printf("%s \n", word_dog);
    reverse(word_dog);
    printf("%s \n", word_dog);
    printf("is_pal %s %d \n", word_dog, is_palindrome(word_dog));
    printf("is_pal %s %d \n", "noon", is_palindrome("noon"));
    printf("has_dup %s %d \n", word_dog, has_dupe(word_dog));
    printf("has_dup %s %d \n", "asdfghj", has_dupe("asdfghj"));
    printf("is anagram %s %s %d \n", "medical", "decimal", is_anagram("medical", "decimal"));
    printf("is anagram %s %s %d \n", "asdf", "dfgh", is_anagram("asdf", "dfgh"));
    // print_perms("abc");
    char alpha[] = "abc";
    better_print_perms(alpha);
    return 0;
}
