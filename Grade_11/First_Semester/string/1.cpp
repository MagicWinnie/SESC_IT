#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s, temp;
    getline(cin, s);
    vector<int> arr = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
            temp += s[i];
        else
        {
            if (temp.find(arr[c]) == string::npos)
            {   
                if (c % 2 == 0)
                {
                    cout << "PLAYER 2" << endl;
                    return 0;
                } else 
                {
                    cout << "PLAYER 1" << endl;
                    return 0;
                }
            }
            temp = "";
            c++;
        }
    }
    if (temp.find(arr[c]) == string::npos)
    {   
        if (c % 2 == 0)
        {
            cout << "PLAYER 2" << endl;
            return 0;
        } else 
        {
            cout << "PLAYER 1" << endl;
            return 0;
        }
    }
    cout << "NO WINNER" << endl;
}