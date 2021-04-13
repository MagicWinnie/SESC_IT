#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    vector<vector<int>> actor_votes;
    vector<vector<int>> car_votes;
    
    int n, m, temp;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp_vec;
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            temp_vec.push_back(temp);
        }
        actor_votes.push_back(temp_vec);
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> temp_vec;
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            temp_vec.push_back(temp);
        }
        car_votes.push_back(temp_vec);
    }
    for (int i = 0; i < n; i++)
    {
        int sum_of_votes = 0;
        for (int j = 0; j < m; j++)
        {
            if (actor_votes[i][j] > 0 && car_votes[i][j] > 0)
            {
                int temp_max_actors = -1, temp_max_cars = -1;
                for (int k = 0; k < n; k++)
                {
                    if (k == i) continue;
                    if (actor_votes[k][j] > temp_max_actors)
                    {
                        temp_max_actors = actor_votes[k][j];
                    }
                    if (car_votes[k][j] > temp_max_cars)
                    {
                        temp_max_cars = car_votes[k][j];
                    }
                }
                if (actor_votes[i][j] >= temp_max_actors && car_votes[i][j] >= temp_max_cars)
                {
                    sum_of_votes++;
                }
            }
        }
        if ((double)sum_of_votes/(double)m >= 0.3)
        {
            cout << "YES" << endl;
            cout << i + 1 << endl;
            return 0;
        }
    }
    int max_val = -1, max_ind = 0;
    for (int i = 0; i < n; i++)
    {
        int sum_of_votes = 0;
        for (int j = 0; j < m; j++)
        {
            sum_of_votes += actor_votes[i][j];
        }
        if (sum_of_votes > max_val)
        {
            max_val = sum_of_votes;
            max_ind = i + 1;
        }
    }   
    cout << "NO" << endl;
    cout << max_ind << endl;
}