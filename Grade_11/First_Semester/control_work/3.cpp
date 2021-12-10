#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s == "Mon")
        cout << 1 << endl;
    else if (s == "Tue")
        cout << 2 << endl;
    else if (s == "Wed")
        cout << 3 << endl;
    else if (s == "Thu")
        cout << 4 << endl;
    else if (s == "Fri")
        cout << 5 << endl;
    else if (s == "Sat")
        cout << 6 << endl;
    else 
        cout << 7 << endl;
    return 0;
}