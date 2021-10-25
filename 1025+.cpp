#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int dayTab[2][13] =
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,28,31,30,31,30,31,31,30,31,30,31}
};
bool isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;
}
char a[9], b[9];
int main() {
	//n为第一个日期相对于0000 00 00的差值，n1为第二个日期的差值
	int year, month, day, year1, month1, day1, n, n1;
	while (cin >> a >> b)
	{
		n = n1 = 0;
		sscanf(a, "%04d-%02d-%02d", year, month, day);
		sscanf(b, "%04d-%02d-%02d", year1, month1, day1);
		for (int i = 0; i <= year; i++)//记录年差值
		{
			if (isLeapYear(i))
			{
				n += 366;
			}
			else n += 365;
		}
		for (int i = 1; i < month; i++)
		{
			n += dayTab[isLeapYear(year)][i];
		}
		n += day;

		for (int i = 0; i <= year1; i++)
		{
			if (isLeapYear(i))
			{
				n1 += 366;
			}
			else n1 += 365;
		}
		for (int i = 1; i < month1; i++)
		{
			n1 += dayTab[isLeapYear(year1)][i];
		}
		n1 += day1;
		cout << abs(n - n1) + 1 << endl;
	}
	return 0;
}
