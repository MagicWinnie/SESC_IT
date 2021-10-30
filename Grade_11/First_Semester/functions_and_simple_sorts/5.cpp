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
    int n;
    unsigned long long a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cout << a * b / nod(a, b) << endl;
    }
}