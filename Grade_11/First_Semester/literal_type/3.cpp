#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    s = s.substr(0, s.size() - 1);
    if (s[s.size() - 1] != '5' && s[s.size() - 1] != '0')
    {
        cout << "NO" << endl;
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] - '0';
    if (sum % 3 != 0)
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;
}