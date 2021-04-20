#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

vector<int> bfs(vector<vector<int>> g, int start)
{
    vector<int> level(g.size(), -1);
    level[start] = 0;

    vector<bool> visited(g.size(), false);
    visited[start] = true;

    vector<int> queue;
    queue.push_back(start);

    while (!queue.empty())
    {
        int v = queue.front();
        queue.erase(queue.begin());
        for (int i = 0; i < g[v].size(); i++)
        {
            int b = g[v][i];
            if (!visited[b])
            {
                visited[b] = true;
                queue.push_back(b);
                level[b] = level[v] + 1;
            }
        }
    }
    return level;
}

int main()
{
    int n, m, k, temp;

    vector<int> roots;

    cin >> n >> m;
    m--;

    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        cin >> k;

        if (k == 0)
            roots.push_back(i);

        for (int j = 0; j < k; j++)
        {
            cin >> temp;
            temp--;
            g[temp].push_back(i);
        }
    }

    // for (int i = 0; i < g.size(); i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < g[i].size(); j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> res;
    for (int r : roots)
    {
        vector<int> level = bfs(g, r);
        for (int i = 0; i < level.size(); i++)
        {
            // cout << level[i] << " " << i << " " << m + 1 << endl;
            if (level[i] == m + 1)
                res.push_back(i);
        }
        level.clear();
    }
    sort(res.begin(), res.end());
    for (int i : res)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
}