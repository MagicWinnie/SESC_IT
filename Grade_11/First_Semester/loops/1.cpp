#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x, eps, y = 0, temp = 0;
    cin >> x >> eps;

    int n = 0;
    while (true)
    {
        temp = pow(-1.0, (double)n) * pow(x, (double)2.0 * n + 1);
        temp = (double)temp / (2.0 * n + 1);
        y += temp;
        n++;
        if (abs(temp) < eps)
            break;
    }
    cout << fixed << setprecision(5) << y << endl;
}