#include <iostream>
#include <cmath>

using namespace std;

unsigned int find_sim_less(unsigned int d, unsigned int n)
{
    unsigned int i = 0;
    unsigned int temp = 0;
    while (true)
    {
        temp = 0;
        for (int j = i; j >= 0; j--)
        {
            temp += d * (int)pow(10, j);
        }
        if (temp > n) break;
        i++;
    }
    temp /= 10;
    return temp;
}

int main()
{
    unsigned int d, n;
    cin >> d;
    cin >> n;

    unsigned int result = 0;
    unsigned int temp = find_sim_less(d, n);
    if (temp == n)
    {
        cout << result << endl;
        return 0;
    }

    unsigned int left = n - temp;
    while (left > 0)
    {
        left -= find_sim_less(d, left);
        result++;
    }
    cout << result << endl;
}