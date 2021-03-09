// You get N pairs, from which you have to choose one number so the sum is max and does not divide by 3.
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    int s = 0, mr = 1000000;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        s += (a > b) ? a : b;
        if (abs(a - b) % 3 != 0 && abs(a - b) < mr)
            mr = abs(a - b);
    }
    if (s % 3 != 0)
        cout << s << endl;
    else
        cout << s - mr << endl;
}
