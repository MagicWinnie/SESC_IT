#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> arr)
{
    int n = arr.size();
    vector<vector<int>> new_arr(n);

    for (int j = 0; j < n; j++)
    {
        vector<int> temp;
        for (int i = n - 1; i >= 0; i--)
            temp.push_back(arr[i][j]);
        new_arr[j] = temp;
    }
    return new_arr;
}

template<typename T>
void print(vector<vector<T>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> key(2 * n, vector<int>(2 * n));
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
            cin >> key[i][j];
    }
    vector<string> pole(2 * n);
    string temp;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> pole[i];
    }
    string out;
    vector<vector<bool>> visited(2 * n, vector<bool>(2 * n, false));

    for (int i = 0; i < 4; i++)
    {
        for (int x = 0; x < 2 * n; x++)
        {
            for (int y = 0; y < 2 * n; y++)
            {
                // cout << visited[x][y] << " " << key[x][y] << endl;
                if (visited[x][y] && key[x][y])
                {
                    cout << "No" << endl;
                    return 0;
                } else if (!visited[x][y] && key[x][y])
                {
                    // cout << pole[x] << endl;
                    out += pole[x][y];
                    visited[x][y] = true;
                }
            }
        }
        // cout << "VISITED: " << endl;
        // print(visited);
        // cout << ": END" << endl;
        key = rotate(key);
        // print(key);
    }
    cout << out << endl;
}