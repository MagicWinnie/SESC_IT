// Circular buffer
#include <iostream>
#include <fstream>
#include <string>
#include "CycleQueue.h"

using namespace std;

int main()
{
    int n, m;
    ifstream file ("input_cycle.txt");
    file >> n >> m;
    CycleQueueClass<int> q(n);
    for (int i = 0; i < m; i++)
    {
        int temp;
        file >> temp;
        if (temp > 0)
        {
            for (int j = 0; j < temp; j++)
            {
                int temptemp;
                file >> temptemp;
                i++;
                try 
                {
                    q.push(temptemp);
                }
                catch (...)
                {
                    cout << "Memory overflow" << endl;
                    for (int k = j + 1; k < temp; k++) { file >> temptemp; i++; }
                    break;
                }
            }
        }
        else 
        {
            int sum = 0, flag = 0, count = 0;
            for (int j = 0; j < temp*(-1); j++)
            {
                try
                {
                    sum += q.pop();
                }
                catch(...)
                {
                    count = j;
                    flag = 1;
                    cout << (int)(sum/(j)) << endl;
                    cout << "Empty queue" << endl;
                    break;
                }
                count++;
            }
            if (flag == 0) cout << (int)(sum/(count)) << endl;
        }
    }
    file.close();
}