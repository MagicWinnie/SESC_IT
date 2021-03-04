// Transform an infix notation to a prefix one.
#include <iostream>
#include <string>
#include <map>
#include <ctype.h>
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

map<char, int> prior {{'(', 1}, {')', 2}, {'=', 3}, {'+', 4}, {'-', 4}, {'*', 5}, {'/', 5}};

int main()
{
    StackClass<char> stk;
    string input, output;
    getline(cin, input);
    input = ReplaceAll(input, " ", "");
    size_t i = 0;
    char X;
    while (true)
    {
        X = input[i];
        if (isdigit(X) || isalpha(X))
        {
            output.push_back(X);
        } else if (X == '(')
        {
            stk.push(X);
        } else if (X == ')')
        {
            while (true)
            {
                if (stk.top() == '(')
                {
                    stk.pop();
                    break;
                } else {
                    output.push_back(stk.pop());
                }
            }
        } else {
            while (!stk.empty() && prior[stk.top()] >= prior[X])
            {
                output.push_back(stk.pop());
            }
            stk.push(X);
        }
        i++;
        if (i >= input.size()) 
        {
            while (!stk.empty())
                output.push_back(stk.pop());
            break;
        }
    }
    cout << output << endl;
}