#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k, temp = 0;
    long int total_size = 0, deleted = 0;
    cin >> k;
    
    string s, temp_str;
    for (int i = 1;; i++)
    {
        if (temp >= 10)
        {
            s = "";
            deleted += temp;
            temp = 0;
        }
        temp_str = to_string(i);
        s += temp_str;
        total_size += temp_str.size();
        if (total_size >= k)
            break;
        temp += temp_str.size();
    }
    cout << s[k - 1 - deleted] << endl;
}