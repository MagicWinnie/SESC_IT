#include <stdio.h>
#include <stdlib.h>

int main()
{
    int type;
    int pX, pY, fX, fY;
    scanf("%d %d %d %d %d", &type, &pX, &pY, &fX, &fY);

    switch (type)
    {
    case 1:
        if ((abs(pX - fX) == 2 && abs(pY - fY) == 1) || (abs(pX - fX) == 1 && abs(pY - fY) == 2))
            printf("yes");
        else
            printf("no");
        break;
    case 2:
        if (abs(pX - fX) == abs(pY - fY))
            printf("yes");
        else
            printf("no");
        break;
    case 3:
        if (pX == fX || pY == fY)
            printf("yes");
        else
            printf("no");
        break;
    case 4:
        if ((pX == fX || pY == fY) || abs(pX - fX) == abs(pY - fY))
            printf("yes");
        else
            printf("no");
        break;
    }
    printf("\n");
    return 0;
}