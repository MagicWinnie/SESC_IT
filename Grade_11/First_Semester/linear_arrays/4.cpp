#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> arr, int x)
{
    int n = arr.size();

    int start = 0, end = n - 1;

    while (start <= end)
    {
        int curr = (start + end) / 2;
        if (x == arr[curr])
            return curr;
        if (x < arr[curr])
            end = curr - 1;
        else
            start = curr + 1;
    }

    return -1;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << binary_search(arr, x) << endl;    
}