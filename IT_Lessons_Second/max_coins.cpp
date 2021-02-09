// how many coins can you get
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    // input
    freopen("input_max_coins.txt", "r", stdin);
    int n = 0, m = 0;
    cin >> n >> m;

    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    fclose(stdin);

    // main
    for (int i = 1; i < m; i++) arr[0][i] += arr[0][i - 1];
    for (int i = 1; i < n; i++) arr[i][0] += arr[i - 1][0];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if (arr[i - 1][j] > arr[i][j - 1]) arr[i][j] += arr[i - 1][j];
            else arr[i][j] += arr[i][j - 1];
        }    
    
    // output
    freopen("output_max_coins.txt", "w", stdout);
    cout << arr[n - 1][m - 1] << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    fclose(stdout);
    return 0;
}