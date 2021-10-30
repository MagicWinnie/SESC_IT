#include <iostream>
#include <algorithm>
#include <vector>

const unsigned int INF = 9999999;

using namespace std;

int main()
{
    unsigned int n, m,
        a, b, t,
        k;
    cin >> n >> m;
    vector<vector<unsigned int>> arr(n, vector<unsigned int>(n, INF));
    for (int i = 0; i < n; i++) arr[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        arr[a - 1][b - 1] = min(t, arr[a - 1][b - 1]);
        arr[b - 1][a - 1] = min(t, arr[b - 1][a - 1]);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int l = 0; l < n; l++)
                arr[j][l] = min(arr[j][l], arr[i][l] + arr[j][i]);

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        cout << arr[a - 1][b - 1] << endl;
    }
}