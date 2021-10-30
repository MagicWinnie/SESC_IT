#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    int d = 2;
    while (d * d <= n && n % d != 0)
        d++;
    return d * d > n;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            cout << i << " ";
    }
    cout << endl;
}