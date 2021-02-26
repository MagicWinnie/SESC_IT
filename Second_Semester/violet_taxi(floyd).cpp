// Using floyd algorithm to solve a problem
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

int main()
{
    int n, m,
        a, b, t,
        k;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) arr[i][j] = USHRT_MAX;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        arr[a - 1][b - 1] = t;
        arr[b - 1][a - 1] = t;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        cout << arr[a - 1][b - 1] << endl;
    }
    return 0;
}
