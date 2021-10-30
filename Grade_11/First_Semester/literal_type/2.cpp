#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    s = s.substr(0, s.size() - 1);
    if (s[1] == 'A' && s.size() == 3)
    {
        cout << "FITS" << endl;
    } else
    {
        cout << "DOES NOT FIT" << endl;
    }
}