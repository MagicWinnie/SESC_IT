#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU");
    ifstream in("input.txt");

    string s;
    vector<int> arr(1000);
    in >> s;
    while (!in.eof())
    {
        arr[strlen(s.c_str())]++;
        in >> s;
    }
    in.close();

    ofstream out("output.txt");
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > 0)
            out << i << " - " << arr[i] << endl;
    }
    out.close();
}