#include <iostream>
#include <math.h>

using namespace std;

bool isInteger(double N)
{
    int X = N;
    double temp2 = N - X;
    if (temp2 > 0)
        return false;
    return true;
}

int main()
{
    int k;
    cin >> k;
    // n^2 + n - 2*k = 0
    double d_1_2 = pow(1.0 + 8.0 * (double)(k - 1), 0.5);
    if (!isInteger(d_1_2))
    {
        cout << 0 << endl;
    } else 
    {
        cout << 1 << endl;
    }
}