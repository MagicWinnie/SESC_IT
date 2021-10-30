#include <stdio.h>
#include "str_lib.h"

int main()
{
    char s[] = "Hello World!";
    char hay[] = "0123456789";
    char needle[] = "456";

    char here[32];
    here[0] = '\0';

    char cmp1[] = "Alina";
    char cmp2[] = "Alena";

    printf("String length: %d\n", strlen(s));

    printf("Before copy: '%s'\n", here);
    strcpy(here, needle);
    printf("After copy: '%s'\n", here);

    printf("Compare 1: %d\n", strcmp(cmp1, cmp2));
    printf("Compare 2: %d\n", strcmp(cmp1, cmp1));
    printf("Compare 3: %d\n", strcmp(cmp2, cmp1));

    printf("Strcat: %s\n", strcat(hay, needle));

    printf("Substring '%s' start at index %d\n", needle, strstr(hay, needle) - hay + 1);
    return 0;
}
