#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    int q, n, k;
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        vector<double> arr(n + 1);
        if (k == 0 || k == n)
        {
            cout << 1 << '\n';
        }
        else 
        {
            arr[0] = 1;
            for (int j = 1; j <= n; j++)
            {
                for (int i = j; i >= 1; i--)
                    arr[i] = arr[i - 1] + arr[i];
            }
            printf("%0.10g\n", arr[k]);
        }
    }
    return 0;
}