// Solving japanese crossword
// Doesn't work
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

vector<int> split(string s, char deli = ' ')
{
    vector<int> out;
    string buffer;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] != deli)
            buffer += s[i]; 
        else
        {
            out.push_back(stoi(buffer));
            buffer = "";
        }
    }
    return out;
}

void print_arr(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void print_arr(vector<vector<bool>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void print_arr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    ifstream input("input_japanese_solver.txt");
    int n, m;
    input >> n >> m;
    string buffer;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> temp_vec;
    for (int i = 0; i < n; i++)
    {
        getline(input >> ws, buffer);
        vector<int> temp = split(buffer);
        temp_vec.push_back(temp);
        int l = 0;
        for (int j = 0; j < temp.size(); j++)
        {
            for (int k = 0; k < temp[j]; k++)
                arr[i][l++] = 1;
            l++;
        }
    }
    cout << endl;
    print_arr(arr);
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        getline(input >> ws, buffer);
        vector<int> temp = split(buffer);
        int l = 0;
        for (int j = 0; j < temp.size(); j++)
        {
            for (int k = 0; k < temp[j]; k++)
                arr[l++][i] = 1;
            if (l < n) arr[l][i] = 0;
            l++;
        }
    }
    cout << endl;
    print_arr(arr);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp = temp_vec[i];
        int l = 0;
        for (int j = 0; j < temp.size(); j++)
        {
            for (int k = 0; k < temp[j]; k++)
                arr[i][l++] = 1;
            l++;
        }
    }
    cout << endl;
    print_arr(arr);
    cout << endl;
}