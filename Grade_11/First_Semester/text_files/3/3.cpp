#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("input.txt");
    int count = 0;
    string temp;
    while (getline(in, temp))
        count++;
    in.close();
    ofstream out("output.txt");
    out << count << endl;
    out.close();
}