#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "MANY" << endl;
                return 0;
            }
            else
            {
                cout << "ERROR" << endl;
                return 0;
            }
        }
        else
        {
            cout << 1 << endl;
            cout << fixed << setprecision(5) << (double)-c / b << endl;
            return 0;
        }
    }
    double d = ((double)b * (double)b - 4.0 * (double)a * (double)c);
    if (d < 0)
    {
        cout << "NO" << endl;
    }
    else if (d == 0)
    {
        cout << 1 << endl;
        cout << fixed << setprecision(5) << (((double)-b + pow(d, 0.5)) / (2.0 * (double)a)) << endl;
    }
    else
    {
        cout << 2 << endl;
        double x1 = (((double)-b + pow(d, 0.5)) / (2.0 * (double)a));
        double x2 = (((double)-b - pow(d, 0.5)) / (2.0 * (double)a));
        if (x1 > x2)
        {
            cout << fixed << setprecision(5) << x2 << " " << x1 << endl;
        }
        else
        {
            cout << fixed << setprecision(5) << x1 << " " << x2 << endl;
        }
    }
}