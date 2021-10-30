#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int from_a_to_10(string s1, int a)
{
    int s = 0;
    for (int i = 0; i < s1.size(); i++)
        s += ((s1[i] >= 'A' && s1[i] <= 'Z') ? (10 + s1[i] - 'A') : (s1[i] - '0')) * pow(a, s1.size() - 1 - i);
    return s;
}
string from_10_to_b(int ten, int b)
{
    string out = "";
    while (ten)
    {
        out = ((ten % b >= 10) ? string(1, 'A' + ten % b - 10) : to_string(ten % b)) + out;
        ten /= b;
    }
    return out;
}

int main()
{
    int a, b;
    string s1;
    cin >> a >> b >> s1;

    // sanity checks
    if (a < 2 || a > 36)
    {
        cout << "ERROR! a should be in [2; 36]" << endl;
        return 0;
    }
    if (b < 2 || b > 36)
    {
        cout << "ERROR! b should be in [2; 36]" << endl;
        return 0;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        if ((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'Z'))
        {}
        else if (s1[i] >= 'a' && s1[i] <= 'z')
            s1[i] = 'A' + (s1[i] - 'a');
        else
        {
            cout << "ERROR! In s2 only alphanumericals are supported!" << endl;
            return 0;
        }
        if (s1[i] >= 'A' && s1[i] <= 'Z' && (int)(s1[i] - 'A') + 10 >= a)
        {
            cout << "ERROR! Error in input!" << endl;
            return 0;
        } else if (s1[i] >= '0' && s1[i] <= '9' && s1[i] - '0' >= a)
        {
            cout << "ERROR! Error in input!" << endl;
            return 0;
        }
    }
    // sanity checks
    // runner
    int in_ten = from_a_to_10(s1, a);
    string in_b = from_10_to_b(in_ten, b);
    cout << in_b << endl;
    // runner
}