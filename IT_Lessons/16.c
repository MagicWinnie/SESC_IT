#include <stdio.h>

struct dateStruct 
{ 
    int d, m, y; 
}; 
  
int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeap(struct dateStruct d)
{
    if ((d.y % 4 == 0 && d.y % 100 != 0) || d.y % 400 == 0)
        return 1;
    return 0;
}

void countLeapYears(struct dateStruct d1, struct dateStruct d2, int *leapYears, int *nonLeapYears) 
{
    while (1)
    {
        d1.y++;
        if (d1.y >= d2.y) break;
        if (isLeap(d1) == 1)
            *leapYears += 1;
        else
            *nonLeapYears += 1;
    }
}

int getDifference(struct dateStruct d1, struct dateStruct d2)
{
    int total = 0, leapYears = 0, nonLeapYears = 0;
    countLeapYears(d1, d2, &leapYears, &nonLeapYears);
    total += 366*leapYears + 365*nonLeapYears;
    if (d1.y == d2.y)
    {
        if (isLeap(d1)) monthDays[1] = 29;
        for (int i = d1.m; i < d2.m - 1; i++)
            total += monthDays[i];
        total += monthDays[d1.m-1] - d1.d;
        total += d2.d;
        return total;
    } else {
        if (isLeap(d1)) monthDays[1] = 29;
        total += monthDays[d1.m - 1] - d1.d;
        for (int i = d1.m; i < 12; i++)
            total += monthDays[i];
        if (isLeap(d2)) monthDays[1] = 29;
        else monthDays[1] = 28;
        for (int i = 0; i < d2.m - 1; i++)
            total += monthDays[i];
        total += d2.d;
        return total;
    }
}
  
int main() 
{
    int d1, m1, y1, d2, m2, y2;
    scanf("%d %d %d %d %d %d", &d1, &m1, &y1, &d2, &m2, &y2);

    struct dateStruct ds1 = {d1, m1, y1}; 
    struct dateStruct ds2 = {d2, m2, y2};
    printf("%d\n", getDifference(ds1, ds2)); 

    return 0; 
} 