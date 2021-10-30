#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

string add_1_2_bin(string x, bool neg)
{
    for (int i = x.size() - 1; i >= 0; i--)
    {
        if (x[i] == ((neg) ? '0' : '1'))
        {
            x[i] = '1';
            for (int j = i + 1; j < x.size(); j++)
                x[j] = '0';
            return x;
        }
    }
    return x;
}

string dec_2_bin(int x)
{
    string s = "";
    bool neg = (x < 0);
    for (int i = 0; i < 32; i++)
        s += '0';
    int i = 0;
    while (x != 0)
    {
        s[s.size() - i - 1] = ((x % 2) ? '1' : '0');
        x /= 2;
        i++;
    }
    if (neg)
    {
        for (int i = 0; i < s.size(); i++)
            s[i] = (s[i] == '1') ? '0' : '1';
        s = add_1_2_bin(s, neg);
    }
    return s;
}

int main()
{
    string s;
    int n;
    cin >> n;
    s = dec_2_bin(n);

    int count = 0, m = -111;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1') count++;
        else
        {
            if (count > m) m = count;
            count = 0;
        }
    }
    if (count > m) m = count;
    cout << m << endl;
}