#include<iostream>
using namespace std;
bool IsLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return true;
	}return false;
}
int dayTab[2][13] =
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int main()
{
	int m, year, month, day, n;
	cin >> m;
	while (m--)
	{
		cin >> year >> month >> day >> n;
		n += day;
		day = 0;//·½±ã¼ÆËã
		while (n >= dayTab[IsLeapYear(year)][month])
		{
			n -= dayTab[IsLeapYear(year)][month];
			day = 0;
			if (month == 12)
			{
				month = 1; year++;
			}
			else {
				month++;
			}
		}
		day += n;
		if (day == 0)
		{
			month--;
			day = dayTab[IsLeapYear(year)][month];
		}
		printf("%04d-%02d-%02d\n", year, month, day);
	}
	return 0;
}