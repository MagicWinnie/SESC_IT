#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool flag = false;
    while (n > 0)
    {
        if (n % 10 != 0 && !flag)
            flag = true;
        if ((n % 10 != 0 && !flag) || (flag)) 
        {
            cout << n % 10;
        }
        n /= 10;
    }
    cout << endl;
}