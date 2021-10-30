#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, s, count = 0;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == s)
                count++;
        }
    }
    cout << count << endl;
}