#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, min_id = 1;
    double min_n = 999999.0, temp, delta_low, delta_high;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        delta_low = abs(temp - floor(temp));
        delta_high = abs(temp - ceil(temp));
        if (delta_low < delta_high)
        {
            if (delta_low < min_n)
            {
                min_id = i;
                min_n = delta_low;
            }
        } else {
            if (delta_high < min_n)
            {
                min_id = i;
                min_n = delta_high;
            }
        }
    }
    cout << min_id << endl;
}