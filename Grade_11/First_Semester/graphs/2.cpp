#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(int s, int f, vector<vector<int>> arr)
{
    int n = arr.size();
    queue<int> q;
    q.push(s);
    
    vector<bool> visited(n, false);
    vector<int> d(n, 0), p(n);
    
    visited[s] = true;
    p[s] = -1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < arr[v].size(); i++)
        {
            int to = arr[v][i];
            if (!visited[to])
            {
                visited[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }

    if (!visited[f])
        return 0;
    else
    {
        vector<int> path;
        for (int v = f; v != -1; v = p[v])
            path.push_back(v);

        return path.size();
    }
}

int main()
{
    int n, m, from, to;
    cin >> m >> n;
    vector<vector<char>> lab(m, vector<char>(n));
    vector<vector<int>> adj(n * m, vector<int>(0));


    int start, finish;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 'S')
                start = i * n + j;
            else if (lab[i][j] == 'F')
                finish = i * n + j;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (lab[i][j] != 'X')
            {
                // up
                if (i >= 1)
                {
                    if (lab[i - 1][j] != 'X')
                    {
                        adj[(i - 1) * n + j].push_back(i * n + j);
                        adj[i * n + j].push_back((i - 1) * n + j);
                    }
                }
                // down
                if (i < m - 1)
                {
                    if (lab[i + 1][j] != 'X')
                    {
                        adj[(i + 1) * n + j].push_back(i * n + j);
                        adj[i * n + j].push_back((i + 1) * n + j);
                    }
                }
                // left 
                if (j >= 1)
                {
                    if (lab[i][j - 1] != 'X')
                    {
                        adj[i * n + j].push_back(i * n + (j - 1));
                        adj[i * n + (j - 1)].push_back(i * n + j);
                    }
                }
                // right
                if (j < n - 1)
                {
                    if (lab[i][j + 1] != 'X')
                    {
                        adj[i * n + j].push_back(i * n + (j + 1));
                        adj[i * n + (j + 1)].push_back(i * n + j);
                    }
                }
            }
        }
    }
    for (int i = 0; i < adj.size(); i++)
    {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    if (start == finish)
        cout << 0 << endl;
    else
    {
        int d = bfs(start, finish, adj);
        cout << d - 1 << endl;
    }
}