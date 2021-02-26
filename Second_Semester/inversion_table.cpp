#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> table(n);
    vector<int> output(n);
    fill(output.begin(), output.end(), USHRT_MAX);
    for (int i = 0; i < n; i++)
        cin >> table[i];
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for (int k = 0; k < n; k++)
        {
            if (output[k] == USHRT_MAX)
            {
                if (j == table[i])
                {
                    output[k] = i + 1;
                    break;
                } else
                {
                    j++;
                }
            }
        }
    }
    for (auto const &c: output) cout << c << " ";
    cout << endl;
}

// 12345 - 
// 13110 - table
// 51342 - output