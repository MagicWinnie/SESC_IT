#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> int2vec(int n)
{
    vector<string> res;
    while (n != 0)
    {
        res.push_back(to_string(n % 10));
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}


void print_vec(int n, int m, vector<vector<int>> arr)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
			cout << arr[i][j] << " ";
        }
		cout << endl;
    }
}

void print_vec(vector<string> arr, string deli = " ") {
    for(int i = 0; i < arr.size(); i++)
		cout << arr[i] << deli;
    cout << endl;
}

map<int, string> d2c {{2, "ABC"}, {3, "DEF"}, {4, "GHI"}, {5, "JKL"}, {6, "MNO"}, {7, "PQRS"}, {8, "TUV"}, {9, "WXYZ"}};

int main()
{
    string name;
    cin >> name;
    
    int num;
    cin >> num;
    
    vector<string> nums = int2vec(num);
    
    int n1 = name.length() + 1;
    int n2 = nums.size() + 1;

    vector<vector<int>> arr(n2, vector<int>(n1));
    
    for(int i = 0; i < n2; i++){
        arr[i][0] = i;
    }
    for(int i = 0; i < n1; i++){
        arr[0][i] = i;
    }
    for(int i = 1; i < n2; i++){
        for(int j = 1; j < n1; j++){
            if (d2c[stoi(nums[i - 1])].find(name[j - 1]) != string::npos)
                arr[i][j] = min(min(arr[i - 1][j] + 1, arr[i][j - 1] + 1), arr[i - 1][j - 1]);
	        else
	            arr[i][j] = min(arr[i - 1][j] + 1, arr[i][j - 1] + 1);
        }
    }

    print_vec(n2, n1, arr);
    
    int i = n2 - 1, j = n1 - 1;

    while(i >= 0 && j >= 0){
        if(arr[i][j] - arr[i][max(j - 1, 0)] == 1){
            nums.erase(nums.begin() + j - 1);
            j--;
        } else if(arr[i][j] - arr[max(0, i - 1)][j] == 1){
            nums.insert(nums.begin() + j, string(1, name[i - 1]));
            i--;
        } else {
            i--;
            j--;
        }
        print_vec(nums);
    }
    print_vec(nums, "");
	cout << arr[n2 - 1][n1 - 1] << endl;
    return 0;
}
