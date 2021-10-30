#include <iostream>
#include <cmath>

using namespace std;

unsigned long long nod(unsigned long long a, unsigned long long b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    cout << nod(a, b) << endl;
}