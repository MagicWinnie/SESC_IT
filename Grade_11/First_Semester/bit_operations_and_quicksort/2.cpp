#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 31; i >= 0; i--)
        cout << (((n>>i) & 1) ? 1 : 0);
    cout << endl;
    int out = 0;
    for (int i = 0; i <= 31; i++)
        out += (((n>>i) & 1) ? 1 : 0) * pow(2, 31 - i);
    cout << out << endl;
    for (int i = 0; i <= 31; i++)
        cout << (((n>>i) & 1) ? 1 : 0);
    cout << endl;
}