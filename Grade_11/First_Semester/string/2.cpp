#include <iostream>
#include <string>
#include <vector>

using namespace std;

void runner(string code, char c1, char c2)
{
    int a = code.find(c1);
    int b = code.find(c2);
    if (a != string::npos && b != string::npos)
    {
        if (a > b)
            cout << b + 1 << " " << a + 1 << endl; 
        else
            cout << a + 1 << " " << b + 1 << endl; 
    }
}

int main()
{
    string result, code;
    cin >> result >> code;
    if (result == "green")
    {
        runner(code, 'Y', 'B');
        return 0;
    } else if (result == "orange")
    {
        runner(code, 'Y', 'R');
        return 0;
    } else 
    {
        runner(code, 'R', 'B');
        return 0;
    }
}