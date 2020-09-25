#include <stdio.h>

int main()
{
    int d1, m1, y1, d2, m2, y2;
    scanf("%d %d %d %d %d %d", &d1, &m1, &y1, &d2, &m2, &y2);
    
    int ak1, ak2, yk1, yk2, mk1, mk2;

    ak1 = (14-m1)/12;
    ak2 = (14-m2)/12;

    yk1 = y1 + 4800 - ak1;
    yk2 = y2 + 4800 - ak2;

    mk1 = m1 + 12*ak1 - 3;
    mk2 = m2 + 12*ak2 - 3;

    int jdn1, jdn2;

    jdn1 = d1 + (153*m1 + 2)/5 + 365*y1 + y1/4 - y1/100 + y1/400 - 32045;
    jdn2 = d2 + (153*m2 + 2)/5 + 365*y2 + y2/4 - y2/100 + y2/400 - 32045;

    printf("%d", jdn2-jdn1);
    
    printf("\n");
        
}