#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inp("24.txt");
    char s, last;
    int size = 0, max_len = 0;
    while (inp >> s)
    {
        if (s == 'P' && last == 'P')
        {
            if (size > max_len)
                max_len = size;
            size = 1;
        }
        else
        {
            last = s;
            size++;
        }
    }
    if (size > max_len)
        max_len = size;

    cout << max_len << endl;
    inp.close();
}