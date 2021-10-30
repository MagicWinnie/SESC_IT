#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void sort(vector<int> &arr)
{
    int n = arr.size();
    int control = n - 1;
	int left  = 0;
	int right = n - 1;
	while (left < right)
    {
		for (int i = left; i < right; i++)
        {
			if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                control = i;
			}
		}
		right = control;
		for (int i = right; i > left; i--) {
			if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                control = i;
			}
		}
		left = control;
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