#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string first, temp;
    cin >> first;
    while (cin >> temp)
    {
        bool flag = false;
        for (int i = 0; i < first.size(); i++)
        {
            if (temp.find(first[i]) != string::npos)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << temp << endl;;
    }
}