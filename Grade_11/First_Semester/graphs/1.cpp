#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(int v, vector<vector<int>> &arr, vector<bool> &visited, vector<int> &comp)
{
    visited[v] = true;
    comp.push_back(v);
    for (int i = 0; i < arr[v].size(); i++)
    {
        if (!visited[arr[v][i]])
            dfs(arr[v][i], arr, visited, comp);
    }
}

int main()
{
    int n, m, from, to;
    cin >> n >> m;

    vector<bool> visited(n, false);
    vector<int> comp;
    vector<vector<int>> arr(n, vector<int>(0));
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        from--;
        to--;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }

    int count = 0;
    vector<int> comps(n);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            comp.clear();
            dfs(i, arr, visited, comp);
            count++;
			for (int j = 0; j < comp.size(); j++)
				comps[comp[j]] = count;
        }   
    }
    cout << count << endl;
    for (int i = 0; i < n; i++)
        cout << comps[i] << " ";
    cout << endl;

}