#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2, out;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s2.find(s1[i]) == string::npos)
            out += s1[i];
    }
    sort(out.begin(), out.end());
    if (out.size() > 0)
        cout << out << endl;
    else
        cout << "Empty Set" << endl;
}