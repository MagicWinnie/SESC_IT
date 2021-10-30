#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    // rows
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                c++;
            if (c != 0 && (arr[i][j] == 0 || j + 1 == m))
            {
                cout << c << " ";
                c = 0;
            }
        }
        cout << endl;
    }
    // columns
    c = 0;
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (arr[j][i] == 1)
                c++;
            if (c != 0 && (arr[j][i] == 0 || j + 1 == n))
            {
                cout << c << " ";
                c = 0;
            }
        }
        cout << endl;
    }
}   