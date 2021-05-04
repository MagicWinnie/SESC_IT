#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

void bfs(vector<vector<int>> g, int start, vector<bool> &visited, vector<int> &level)
{
    level[start] = 0;
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
            if (true)//!visited[b])
            {
                queue.push_back(b);
                // for (int _i = 0; _i < queue.size(); _i++)
                //     cout << queue[_i] << " ";
                // cout << endl;
                visited[b] = true;
                // cout << level[b] << " " << level[v] + 1 << endl;
                if (level[b] < level[v] + 1)
                {
                    level[b] = level[v] + 1;
                }
            }
        }
    }
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

    vector<int> level(g.size(), -1);
    vector<bool> visited(g.size(), false);
    vector<int> res;
    for (int r : roots)
    {
        bfs(g, r, visited, level);
        for (int i = 0; i < level.size(); i++)
        {
            // cout << "LEVEL\n\t";
            // for (int i = 0; i < g.size(); i++)
            //     cout << level[i] << " ";
            // cout << endl;
            
            // cout << "VISITED\n\t";
            // for (int i = 0; i < g.size(); i++)
            //     cout << visited[i] << " ";
            // cout << endl;

            // cout << r << " " << level[i] << " " << m + 1 << " " << i << endl;
            if ((level[i] == m + 1) && (find(res.begin(), res.end(), i) == res.end()))
                res.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    for (int i : res)
        cout << i + 1 << " ";
    cout << endl;
}