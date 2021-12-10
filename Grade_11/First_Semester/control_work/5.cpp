#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{  
    vector<long long> arr;
    long long temp;
    while (cin >> temp)
        arr.push_back(temp);
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if ((arr[i - 1] + arr[i + 1]) / 2 != arr[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << arr[1] - arr[0] << endl;
    return 0;
}