// Calculations on a stack. Count the value by its postfix notation.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "stack.h"

using namespace std;

string ReplaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

vector<string> split(string s, char deli = ' ')
{
    vector<string> out;
    string buffer;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] != deli)
            buffer += s[i]; 
        else
        {
            out.push_back(buffer);
            buffer = "";
        }
    }
    if (buffer != "") out.push_back(buffer);
    return out;
}

int main()
{
    StackClass<float> stk;
    string inp;
    vector<string> input;
    float output;
    getline(cin, inp);
    input = split(inp);
    size_t i = 0;
    string X;
    while (true)
    {
        X = input[i];
        if (X != "+" && X != "-" && X != "/" && X != "*")
        {
            stk.push((float)stoi(X));
        } else
        {
            float second = stk.pop();
            float first = stk.pop();
            if (X == "+")
                stk.push(first + second);
            else if (X == "-")
                stk.push(first - second);
            else if (X == "*")
                stk.push(first * second);
            else
                stk.push(first / second);
        }
        i++;
        if (i >= input.size()) 
        {
            output = stk.pop();
            break;
        }
    }
    cout << output << endl;
}