// Solving task №25 from USE
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    fstream f("input_25.txt");
    string input;
    unsigned int m = 0, count = 0;
    getline(f, input);
    for (int i = 0; i < input.size(); i++)
    {
        if ((input[i] == input[i + 1]) || (i + 1 >= input.size()))
        {
            m = max(m, count + 1);
            count = 0;
        } else 
        {
            count++;
        }
    }
    cout << m << endl;
}