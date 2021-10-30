#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int min(vector<int> arr, int start)
{
    int m_item = INT_MAX, m_ind = 0;
    for (int i = start; i < arr.size(); i++)
    {
        if (arr[i] < m_item)
        {
            m_item = arr[i];
            m_ind = i;
        }
    }
    return m_ind;
}

void sort(vector<int> &arr)
{
    int n = arr.size(), m_ind = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        m_ind = min(arr, i);
        swap(arr[j], arr[m_ind]);
        j++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}