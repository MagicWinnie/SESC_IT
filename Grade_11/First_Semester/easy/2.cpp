#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, m, p, k, l;
    cin >> n >> m >> p >> k >> l;
    int per_floor = ceil((double)m / (l * (p - 1) + k));
    int pod = ceil((double)n / per_floor / l);
    int start = (n - per_floor * l * (pod - 1));
    cout << pod << " " << ceil((double)start/per_floor) << endl;
}