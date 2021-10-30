#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    setlocale (LC_ALL, "ru_RU");
    vector<int> arr(256);
    ifstream inp("input.txt");
    char temp;
    unsigned char temp_u;
    while (!inp.eof())
    {
        inp.get(temp);
        temp_u = (unsigned char)temp;
        arr[(int)temp_u]++;
    }
    ofstream out("output.txt");
    for (int i = 13; i < arr.size(); i++)
    {
        if (arr[i] > 0)
            out << i << " : " << (unsigned char)i << " - " << arr[i] << endl;
    }
    out.close();
}