#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    s = s.substr(0, s.size() - 1);
    if (s.substr(s.size() - 2, s.size()) == "er")
    {
        cout << s.substr(0, s.size() - 1) + "st" << endl;
    } else if (s[s.size() - 1] == 'e')
    {
        cout << s + 'r' << endl;
    } else
    {
        cout << s + "er" << endl;
    }
}