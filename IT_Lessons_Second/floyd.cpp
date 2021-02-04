#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>
#include <Windows.h>

using namespace std;

void print_vec(vector<vector<int>> arr)
{
    cout << "-----------------------------------\n";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i][j] == USHRT_MAX) cout << "∞ ";
            else cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------\n";
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    string temp;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (temp == "inf" || temp == "-1") arr[i][j] = USHRT_MAX;
            else arr[i][j] = stoi(temp);
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    print_vec(arr);
    return 0;
}
