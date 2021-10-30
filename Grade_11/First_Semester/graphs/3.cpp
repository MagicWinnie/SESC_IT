#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#define INF 999999

using namespace std;

vector<int> dijkstra(vector<vector<int>> graph, int start)
{
    int n = graph.size();
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    distances[start] = 0;
    
    while (true)
    {
        int shortest_distance = INF;
        int shortest_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (distances[i] < shortest_distance && !visited[i])
            {
                shortest_distance = distances[i];
                shortest_index = i;
            }
        }
        if (shortest_index == -1)
            return distances;
        for (int i = 0; i < graph[shortest_index].size(); i++)
        {
            if ((graph[shortest_index][i] != 0) && (distances[i] > distances[shortest_index] + graph[shortest_index][i]))
                distances[i] = distances[shortest_index] + graph[shortest_index][i];
        }
        visited[shortest_index] = true;
    }
}

int main()
{
    int n, start, finish;
    cin >> n;
    
    cin >> start >> finish;
    start--; finish--;
    vector<vector<int>> arr(n, vector<int>(n, 0));

    int a, b, c;
    while (cin >> a >> b >> c)
    {
        arr[a - 1][b - 1] = c;
        arr[b - 1][a - 1] = c;
    }

    vector<int> d = dijkstra(arr, start);

    cout << ((d[finish] == INF) ? "no" : to_string(d[finish])) << endl;

    // for (int i = 0; i < d.size(); i++)
    //     cout << d[i] << ' ';
    // cout << endl;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr[i].size(); j++)
    //         cout << arr[i][j] << ' ';
    //     cout << endl;
    // }
}