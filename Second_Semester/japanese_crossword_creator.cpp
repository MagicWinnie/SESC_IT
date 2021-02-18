// Solving japanese crossword
// Yeah, I might have just splitted the strings...
#include <iostream>
#include <vector>
#include <string>
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

void print_arr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    ifstream input("input_japanese_creator.txt");
    ofstream output("input_japanese_solver.txt");
    int n, m;
    input >> n >> m;
    output << n << " " << m << endl;
    string buffer;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            input >> arr[i][j];

    for (int i = 0; i < n; i++)
    {
        vector<int> temp_hor;
        bool flag_hor = false;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                if (!flag_hor)
                {
                    temp_hor.push_back(1);
                    flag_hor = true;
                } else 
                {
                    temp_hor[temp_hor.size() - 1]++;
                }
                if (j + 1 < m)
                {
                    if (arr[i][j + 1] == 0)
                        flag_hor = false;    
                } else if (j + 1 >= m)
                {
                    flag_hor = false;
                }
            }
        }
        cout << temp_hor.size() << endl;
        for (int i = 0; i < temp_hor.size(); i++) output << temp_hor[i] << " ";
        output << endl;
    }

    for (int j = 0; j < m; j++)
    {
        vector<int> temp_ver;
        bool flag_ver = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] == 1)
            {
                if (!flag_ver)
                {
                    temp_ver.push_back(1);
                    flag_ver = true;
                } else 
                {
                    temp_ver[temp_ver.size() - 1]++;
                }
                if (i + 1 < n)
                {
                    if (arr[i + 1][j] == 0)
                        flag_ver = false;    
                } else if (i + 1 >= n)
                {
                    flag_ver = false;
                }
            }
        }
        cout << temp_ver.size() << endl;
        for (int i = 0; i < temp_ver.size(); i++) output << temp_ver[i] << " ";
        output << endl;
    }

    input.close();
    output.close();
}