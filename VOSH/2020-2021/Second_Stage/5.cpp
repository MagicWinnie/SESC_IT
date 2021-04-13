#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int result = 0;
    vector<pair<int, int>> points;
    vector<double> angles;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        // angles.push_back(abs(atan2((double)temp.second, (double)temp.first)));
        points.push_back(temp);
    }   

    // for (int i = 0; i < angles.size(); i++)
    //     cout << angles[i] << " ";
    // cout << endl;
    
    
}

// y = kx + b