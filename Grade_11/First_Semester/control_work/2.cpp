#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    int n, temp;
    cin >> n;
    while (n--)
    {
        cin >> temp;
        s.insert(temp);
    }
    cout << s.size() << endl;
}