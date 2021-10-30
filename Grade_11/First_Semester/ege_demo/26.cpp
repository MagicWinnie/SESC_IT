#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inp("26.txt");
    int s, n;
    inp >> s >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        inp >> arr[i - 1];
    inp.close();
    sort(arr.begin(), arr.end());
    int max_count = -1, max_el = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[i], j, count = 0, el = arr[i];

        for (j = 0; j < i && temp <= s; j++)
            temp += arr[j], count++;
        if (temp > s)
            temp -= arr[j], count--;

        if (count > max_count)
        {
            max_count = count;
            max_el = el;
        }
    }
    cout << max_count << " " << max_el << endl;
}