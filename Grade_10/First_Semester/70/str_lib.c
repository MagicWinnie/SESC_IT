#include <stdio.h>
#include "str_lib.h"

size_t strlen(const char *s)
{
    size_t length = 0;
    while (s[length] != '\0')
        length++;
    return length;
}

char *strcpy(char *toHere, const char *fromHere)
{
    int i = 0;
    for (i = 0; fromHere[i] != '\0'; ++i)
        toHere[i] = fromHere[i];
    toHere[i] = '\0';
    return toHere;
}

int strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] == '\0')
            return 1;
        else if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
        i++;
    }
    if (s2[i] == '\0')
        return 0;
    else
        return -1;
}

char *strcat(char *dest, const char *src)
{
    int i, j;
    i = strlen(dest);
    for (j = 0; src[j] != '\0'; i++, j++)
    {
        dest[i] = src[j];
    }
    dest[i] = '\0';
    return dest;
}

char *strstr(const char *haystack, const char *needle)
{
    while (*haystack)
    {
        char *b = haystack;
        char *p = needle;
        while (*haystack && *p && *haystack == *p)
        {
            haystack++;
            p++;
        }
        if (!*p)
            return b;

        haystack = b + 1;
    }
    return NULL;
}
