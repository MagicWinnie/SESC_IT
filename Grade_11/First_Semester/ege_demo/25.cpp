#include <iostream>

using namespace std;

int main()
{
    long long start = 700000, count = 0, m, end = 8, m_1 = 0, m_2 = 0;
    start++;
    
    while (count < 5)
    {
        int temp_ind = 2;
        while (temp_ind * temp_ind <= start)
        {
            if (start % temp_ind == 0)
            {
                m_1 = temp_ind;
                m_2 = start / temp_ind;
                break;
            }
            temp_ind++;
        }
        m = m_1 + m_2;
        if (m % 10 == end)
        {
            cout << start << " " << m << endl;
            count++;
        }
        start++;
    }
}