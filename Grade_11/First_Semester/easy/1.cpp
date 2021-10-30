#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double dist(int a_x, int a_y, int b_x, int b_y)
{
    return pow(
        pow((double)(a_x - b_x), 2.0) + 
        pow((double)(a_y - b_y), 2.0),
        0.5
    );
}

int main()
{
    cout.precision(3);

    int a_x, a_y, b_x, b_y, c_x, c_y;
    cin >> a_x >> a_y;
    cin >> b_x >> b_y;
    cin >> c_x >> c_y;
    double a, b, c;
    a = dist(a_x, a_y, b_x, b_y);
    b = dist(c_x, c_y, b_x, b_y);
    c = dist(a_x, a_y, c_x, c_y);
    double p = a + b + c;
    cout << fixed << p << endl;
    cout << fixed << pow(p/2.0 * (p/2.0 - a) * (p/2.0 - b) * (p/2.0 - c), 0.5) << endl;
}