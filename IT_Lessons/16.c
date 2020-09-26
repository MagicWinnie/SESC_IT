#include <stdio.h>

struct dateStruct 
{ 
    int d, m, y; 
}; 
  
int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

int leapYears(struct dateStruct d) 
{ 
    int years = d.y; 
   
    if (d.m <= 2)
        years--; 
  
    return years / 4 - years / 100 + years / 400; 
} 
  
int getDifference(struct dateStruct ds1, struct dateStruct ds2) 
{ 
    long int n1 = ds1.y*365 + ds1.d; 
  
    for (int i=0; i<ds1.m - 1; i++) 
        n1 += monthDays[i]; 
  
    n1 += leapYears(ds1); 
  
    long int n2 = ds2.y*365 + ds2.d; 
    for (int i=0; i<ds2.m - 1; i++) 
        n2 += monthDays[i]; 
    n2 += leapYears(ds2); 
  
    return (n2 - n1); 
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