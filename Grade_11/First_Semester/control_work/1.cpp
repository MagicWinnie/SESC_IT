#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x, eps, res = 0, temp = 1000;
    cin >> x >> eps;

    int n = 0;
    while (abs(temp) > eps)
    {
        temp = pow(-1.0, n) * pow(x, 2 * n + 1) / (2 * n + 1);
        res += temp;
        n++;
    }

    cout << fixed << setprecision(5) << res;
}