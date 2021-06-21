// Shortest path in graph using dijsktra algorithm
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

int minDistance(vector<int> dist, vector<bool> visited) 
{ 
    int min = USHRT_MAX, min_index;

    for (int v = 0; v < visited.size(); v++) 
        if (visited[v] == false && dist[v] <= min) 
        {
            min = dist[v];
            min_index = v; 
        }

    return min_index; 
}

void Dijsktra(vector<vector<int>> G, int start, int end)
{
    vector<bool> visited(G.size());
    vector<int> prev(G.size());
    vector<int> dist(G.size());
    for (int v = 0; v < G.size(); v++)
    {
        prev[v] = -1;
        dist[v] = USHRT_MAX;
        visited[v] = false;
    }
    dist[start] = 0;
    for (int i = 0; i < G.size() - 1; i++)
    {
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < G.size(); v++)
        {
            if (!visited[v] && G[u][v] && dist[u] + G[u][v] < dist[v]) 
            { 
                prev[v] = u; 
                dist[v] = dist[u] + G[u][v];
            }  
        }
    }
    vector<int> s;
    int u = end;
    if (prev[u] != -1 || u == start)
    {
        while (u != -1)
        {
            s.push_back(u);
            u = prev[u];
        }
    }
    reverse(s.begin(), s.end());

    cout << "WEIGHT: " << dist[end] << endl;
    cout << "PATH: ";
    for (int i = 0; i < s.size(); i++) cout << s[i] << " ";
    cout << endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int n, start, end;
    cin >> n >> start >> end;
    vector<vector<int>> arr(n, vector<int>(n));
    string temp;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (temp == "inf" || temp == "0" || temp == "-1") arr[i][j] = USHRT_MAX;
            else arr[i][j] = stoi(temp);
        }
    print_vec(arr);
    Dijsktra(arr, start, end);
    return 0;
}
