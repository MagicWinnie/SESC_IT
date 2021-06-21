// Task #25 from USE on IT
#include <iostream>

using namespace std;

int main()
{
    int start = 174457, end = 174505;
    // int start = 5, end = 9;
    for (int i = start; i <= end; i++)
    {
        int d = 2;
        int a = -1, b = -1;
        bool flag = false;
        while (d * d <= i)
        {
            if (i % d == 0)
            {
                if (flag) { a = -1; b = -1; break; }
                flag = true;            
                if (d != i / d) 
                {
                    a = d;
                    b = i / d;
                } 
            }
            d++;
        }
        if (a != -1 && b != -1)
        {
            if (a > b)
                cout << b << " " << a << endl;
            else 
                cout << a << " " << b << endl;
        }
    }
}
