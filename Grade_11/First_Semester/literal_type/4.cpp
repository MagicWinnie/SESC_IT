#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    // cin >> s;
    getline(cin, s);
    s = s.substr(0, s.size() - 1);
    string temp = "";
    long long sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            temp += s[i];
        else if (temp.size() > 0) 
        {
            sum += stoi(temp);
            temp = "";
        }
    }
    cout << sum << endl;
}