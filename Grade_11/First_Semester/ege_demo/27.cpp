#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inp("27_B.txt");

    int n, k = 43, temp, ost;
    long long curr_sum = 0, max_sum = 0, len = INT_MAX;
    inp >> n;

    vector<int> s_ost(k, INT_MAX); s_ost[0] = 0;
    vector<int> ind(k, 0); ind[0] = -1;
    for (int i = 0; i < n; i++)
    {
        inp >> temp;
        curr_sum += temp;
        ost = curr_sum % k;
        if (curr_sum - s_ost[ost] == max_sum)
            len = min(len, (long long)i - ind[ost]);
        if (curr_sum - s_ost[ost] >  max_sum)
        {
            max_sum = curr_sum - s_ost[ost];
            len = i - ind[ost];
        }
        if (s_ost[ost] == INT_MAX)
        {
            s_ost[ost] = curr_sum;
            ind[ost] = i;
        }
    }
    cout << len << endl;

    inp.close();
}