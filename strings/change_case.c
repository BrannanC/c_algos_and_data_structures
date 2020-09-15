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

    return 0;
}