// Queue implementation
#include <iostream>
#include "queue_custom.h"

using namespace std;

int main()
{
    int n, temp;
    QueueClass<int> qc;

    cout << "Enter n: " << endl;
    cin >> n;

    cout << "Enter numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        qc.push(temp);
    }
    cout << "----------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << qc.pop() << endl;
    }
}