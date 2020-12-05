#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 10    

struct Student 
{
    int id;
    char *name;
    float mathAverage;
    float physAverage;
};

void printStudents(struct Student Students[])
{
    printf("ID\tName\t\tAvg.Maths\tAvg.Physics\n");
    for (int i = 0; i < N; i++)
        printf("%d\t%s\t\t%f\t%f\n", Students[i].id, Students[i].name, Students[i].mathAverage, Students[i].physAverage);
    printf("\n");
}

float float_rand()
{
    float scale = rand()/(float) RAND_MAX;
    return 1 + scale*5;
}

void sortStudents(struct Student Students[], int type)
{
    struct Student temp;
    
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < (N-i-1); j++)
        {
            switch (type)
            {
            case 1:
                if (Students[j].id > Students[j+1].id)
                {
                    temp = Students[j];
                    Students[j] = Students[j+1];
                    Students[j+1] = temp;
                }
                break;
            case 2:
                if (strcmp(Students[j].name, Students[j+1].name) >= 0)
                {
                    temp = Students[j];
                    Students[j] = Students[j+1];
                    Students[j+1] = temp;
                }
                break;
            case 3:
                if (Students[j].mathAverage > Students[j+1].mathAverage)
                {
                    temp = Students[j];
                    Students[j] = Students[j+1];
                    Students[j+1] = temp;
                }
                break;
            case 4:
                if (Students[j].physAverage > Students[j+1].physAverage)
                {
                    temp = Students[j];
                    Students[j] = Students[j+1];
                    Students[j+1] = temp;
                }
                break;
            default:
                if (Students[j].id > Students[j+1].id)
                {
                    temp = Students[j];
                    Students[j] = Students[j+1];
                    Students[j+1] = temp;
                }   
            } 
        }
    }
}


int main()
{
    srand(time(NULL));
    char* names[N] = {"Dmitrii", "Alex", "Nikita", "Nikolay", "Alina", "Elena", "Maxim", "Egor", "Igor", "Alena"};
    struct Student Students[N];
    for (int i = 0; i < N; i++)
    {
        Students[i].id = i+1;
        Students[i].name = names[rand()%N];
        Students[i].mathAverage = float_rand();
        Students[i].physAverage = float_rand();
    }
    sortStudents(Students, 1);
    printStudents(Students);
    sortStudents(Students, 2);
    printStudents(Students);
    sortStudents(Students, 3);
    printStudents(Students);
    sortStudents(Students, 4);
    printStudents(Students);
    return 0;
}