#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#define M_PI 3.14159265358979323846

using namespace std;

int main()
{
    int n;
    cin >> n;

    int result = 0;
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        points.push_back(temp);
    }

    vector<int> out;

    for (int i = 0; i < n; i++)
    {
        vector<float> angles;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            pair<int, int> p0, p1;
            if (points[i].second > points[j].second)
            {
                p0 = make_pair(points[j].first, points[j].second);
                p1 = make_pair(points[i].first, points[i].second);
            }
            else
            {
                p1 = make_pair(points[j].first, points[j].second);
                p0 = make_pair(points[i].first, points[i].second);
            }

            float atg = atan2((float)p1.second - (float)p0.second, (float)p1.first - (float)p0.first);

            if (atg == M_PI)
                atg = 0.0;
            angles.push_back(atg);
        }
        map<float, int> counters;
        for (auto i : angles)
            ++counters[i];
        int currentMax = 0;
        int arg_max = 0;
        for (auto it = counters.cbegin(); it != counters.cend(); ++it)
        {
            if (it->second > currentMax)
            {
                arg_max = it->first;
                currentMax = it->second;
            }
        }
        out.push_back(currentMax + 1);
    }
    cout << *max_element(out.begin(), out.end()) << endl;
}
