#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

unsigned long long C(unsigned long long n, unsigned long long k)
{
    unsigned long long res = 1;
 
    if (k > n - k)
        k = n - k;

    for (unsigned long long i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}

unsigned long long solve(unsigned long long p, unsigned long long v)
{
    unsigned long long a = max(p, v);
    unsigned long long b = min(p, v);

    return C(p + v - 1, max(p, v) - 1);
}

int main()
{
    int P1, V1;
    int P2, V2;
    int P3, V3;

    cin >> P1 >> V1;
    cin >> P2 >> V2;
    cin >> P3 >> V3;

    unsigned long long a = solve(P1, V1);
    unsigned long long b = solve(P2, V2);
    unsigned long long c = solve(P3, V3);

    unsigned long long res = solve(P1, V1) * solve(P2, V2) * solve(P3, V3);

    cout << res << endl;
}