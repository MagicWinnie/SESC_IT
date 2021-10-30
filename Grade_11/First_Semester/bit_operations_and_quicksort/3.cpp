#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot) { i++; swap(arr[i], arr[j]); }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        sort(arr, low, p - 1);
        sort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, 0, arr.size() - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}