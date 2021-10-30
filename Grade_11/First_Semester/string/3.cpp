#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> split(string s)
{
    vector<string> out;
    string temp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
            temp += s[i];
        else
        {
            out.push_back(temp);
            temp = "";
        }
    }
    out.push_back(temp);
    return out;
}
string lower(string s)
{
    string out;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            out += s[i] + 32;
        else
            out += s[i];
    }
    return out;
}
string upper(string s)
{
    string out;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            out += s[i] - 32;
        else
            out += s[i];
    }
    return out;
}
string remove_non_alpha(string s)
{
    string out;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            out += s[i];
    }
    return out;
}
string findEntryWithLargestValue(map<string, int> count)
{
    string m_str;
    int m_val = -99999;
  
    map<string, int>::iterator curr;
    for (curr = count.begin(); curr != count.end(); ++curr)
    {
        if (curr->second > m_val)
        {
            m_val = curr->second;
            m_str = curr->first;
        }
    }

    return m_str;
}

int main()
{
    string ignore_raw, text_raw, temp;
    getline(cin, ignore_raw);
    vector<string> ignore = split(ignore_raw);
    for (int i = 0; i < ignore.size(); i++)
        ignore[i] = lower(ignore[i]);
    
    while (cin >> temp)
    {
        text_raw += temp + ' ';
    }
    vector<string> text = split(text_raw);
    map<string, int> count;
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = remove_non_alpha(lower(text[i]));
        if (find(ignore.begin(), ignore.end(), text[i]) != ignore.end())
            continue;
        if (count.find(text[i]) == count.end())
            count[text[i]] = 1;
        else 
            count[text[i]]++;
    }
    cout << upper(findEntryWithLargestValue(count)) << endl;
}