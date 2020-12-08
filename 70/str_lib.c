#include <stdio.h>
#include "str_lib.h"

size_t strlen(const char* s)
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
    for(i = 0; s1[i] == s2[i] && s1[i] == '\0'; i++);
    if(s1[i] < s2[i])
        return -1;
    else if(s1[i] > s2[i])
        return 1;
    return 0;
}

char *strcat(char *dest, const char *src)
{
    int i = 0, j = 0;
    for (i = 0; src[i] != '\0'; ++i);
    j = 0;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

char *strstr(const char *haystack, const char *needle)
{
    const char *temp_h = haystack;
    const char *temp_n = needle;
    do {
        if (*haystack == *needle)
        {
            haystack++;
            needle++;
        } else 
        {
            haystack++;
            needle = temp_n;
        } 
    } while (*haystack && *needle);
    
    return NULL;
}
