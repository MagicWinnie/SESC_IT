// generate next alphabetic permutation using dijsktra algorithm
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(vector<int> arr)
{
    for (auto &c: arr) cout << c << " ";
    cout << endl;
}

int main()
{
    int n;    
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            int m = arr[i + 1];
            int ind = i + 1;
 
            for (int j = i + 1; j < n; j++)
                if (arr[i] < arr[j] && arr[j] < m) { m = arr[j]; ind = j; }
 
            swap(arr[i], arr[ind]);

            sort(arr.begin() + (i + 1), arr.end());
            print_vec(arr);
            break;
        }
    }
}