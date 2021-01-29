#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void printarr(int n, int m, int** arr){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
			cout << arr[i][j] << " ";
        }
		cout << endl;
    }
}

int main(){
    string s1("abcabba");
    string s2("baca");
    int n1 = s1.length() + 1;
    int n2 = s2.length() + 1;
    int** arr = (int**)malloc(n2 * sizeof(int*));
    for(int i = 0; i < n2; i++){
        arr[i] = (int*)calloc(n1, sizeof(int));
    }
    for(int i = 0; i < n2; i++){
        arr[i][0] = i;
    }
    for(int i = 0; i < n1; i++){
        arr[0][i] = i;
    }
    for(int i = 1; i < n2; i++){
        for(int j = 1; j < n1; j++){
	        if(s2[i - 1] != s1[j - 1]){
	            arr[i][j] = min(arr[i - 1][j] + 1, arr[i][j - 1] + 1);
            }
            else{
                arr[i][j] = min(min(arr[i - 1][j] + 1, arr[i][j - 1] + 1), arr[i - 1][j - 1]);
            }
        }
    }

    printarr(n2, n1, arr);
    
    int i = n2 - 1, j = n1 - 1;

    while(i >= 0 && j >= 0){
        if(arr[i][j] - arr[i][max(j - 1, 0)] == 1){
            s1.erase(j - 1, 1);
            j--;
        } else if(arr[i][j] - arr[max(0, i - 1)][j] == 1){
            s1.insert(j, 1, s2[i - 1]);
            i--;
        } else {
            i--;
            j--;
        }
		cout << s1 << endl;
    }
    cout << s1 << " " << s2 << endl;
	cout << arr[n2 - 1][n1 - 1] << endl;
    return 0;
}
