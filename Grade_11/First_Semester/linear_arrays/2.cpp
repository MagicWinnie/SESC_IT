#include <iostream>

using namespace std;

int min_arr(int *arr, int prev, int n)
{
    for (int i = prev; i < n; i++)
    {
        if (arr[i] != -1)
            return i;
    }
    return -1;
}

void runner(int *arr, int n, int ind)
{
    int k = arr[ind];
    for (int i = ind + k; i < n; i += k)
        arr[i] = -1;
}

int main()
{
    int n;
    cin >> n;

    int m = n - 1;
    int *arr = new int[m];
    for (int i = 0; i < m; i++)
        arr[i] = i + 2;
    

    int prev = 0;
    int k = min_arr(arr, prev, m);
    while (arr[k] * arr[k] <= n)
    {   
        runner(arr, m, k);
        k = min_arr(arr, prev++, m);
    }

    for (int i = 0; i < m; i++)
    {
        if (arr[i] != -1)
            cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}