#include <iostream>

using namespace std;

int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date
{
    int day;
    int month;
    int year;
    bool isLeapYear;
};

bool isLeap(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    return false;
}

bool checkDays(Date date)
{
    int numberOfDays = month_days[date.month - 1];
    if (date.month == 2)
        numberOfDays = (date.isLeapYear) ? 29 : 28;
    
    if (date.day < 1 || date.day > numberOfDays)
        return false;
    return true;
}

int countDaysInMonths(int month_1, int month_2, bool isLeap)
{
    int count = 0;
    for (int m = month_1 + 1; m < month_2; m++)
        count += ((m == 2) ? ((isLeap) ? 29 : 28) : (month_days[m - 1]));
    return count;
}

int main()
{
    Date date_1, date_2;
    cin >> date_1.day >> date_1.month >> date_1.year;
    cin >> date_2.day >> date_2.month >> date_2.year;

    date_1.isLeapYear = isLeap(date_1.year);
    date_2.isLeapYear = isLeap(date_2.year);

    // sanity check
    if (date_1.year > date_2.year) swap(date_1, date_2);
    if (date_1.year == date_2.year)
    {
        if (date_1.month > date_2.month) swap(date_1, date_2);
        if (date_1.month == date_2.month && date_1.day > date_2.day) swap(date_1, date_2);
    }
    if (date_1.year < 1 || date_1.year > 2012) { cout << "ERROR" << endl; return 0; }
    if (date_2.year < 1 || date_2.year > 2012) { cout << "ERROR" << endl; return 0; }
    if (date_1.month < 1 || date_1.month > 12) { cout << "ERROR" << endl; return 0; }
    if (date_2.month < 1 || date_2.month > 12) { cout << "ERROR" << endl; return 0; }
    if (!checkDays(date_1)) { cout << "ERROR" << endl; return 0; }
    if (!checkDays(date_2)) { cout << "ERROR" << endl; return 0; }

    int output = 0;
    for (int y = date_1.year + 1; y < date_2.year; y++)
        output += (isLeap(y)) ? 366: 365;
    if (date_1.year != date_2.year)
    {
        output += countDaysInMonths(date_1.month, 12 + 1, date_1.isLeapYear); // count days in (date_1.month, 12]
        output += countDaysInMonths(0, date_2.month, date_2.isLeapYear); // count days in [1, date_2.month)
    } else
        output += countDaysInMonths(date_1.month, date_2.month, date_1.isLeapYear); // count days in (date_1.month, date_2.month)

    if (date_1.year == date_2.year && date_1.month == date_2.month)
    {
        output += date_2.day - date_1.day;
    } else //if (date_1.month != date_2.month)
    {
        // count days in (date_1.day, max_days]
        int days = month_days[date_1.month - 1];
        if (date_1.month == 2)
            days = (date_1.isLeapYear) ? 29 : 28;
        output += days - date_1.day;
        output += date_2.day;
    }
    cout << output << endl;    
}

/*
1 1 1
1 1 2001
MY: 730454
MAXIM: 730485 
*/