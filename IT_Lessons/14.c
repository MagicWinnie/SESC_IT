#include <stdio.h>


int main()
{
    int tA, tB, tC, a, b, c;

    scanf("%d %d %d", &tA, &tB, &tC);

    if (tA > tB && tA > tC)
    {
        a = tC;
        b = tB;
        c = tA;
    } else if (tB > tA && tB > tC)
    {
        a = tC;
        b = tA;
        c = tB;
    } else
    {
        a = tB;
        b = tA;
        c = tC;
    }
    if ((a + b > c) && (b + c > a) && (a + c > b))
    {
        if (a == b || b == c || a == c)
            printf("Равнобедренный\n");
        else if (a == b && b== c)
            printf("Правильный\n");
        if (c*c == a*a + b*b)
            printf("Прямоугольный\n");
        else if (c*c > a*a + b*b)
            printf("Тупоугольный\n");
        else
            printf("Остроугольный\n");
    } else {
        printf("Не существует\n");
    }        
}