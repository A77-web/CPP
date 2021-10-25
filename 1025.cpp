#include<iostream>
using namespace std;
int dayTab[2][13] =
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};
bool isLeapyear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;
}
int main()
{
	int  month, day, num;
	int year = 0;
	int k = isLeapyear(year);
	while (cin >> year >> num)
	{
		month = 0;
		while (num > dayTab[k][month])
		{
			num -= dayTab[k][month];
			month++;
		}
		day = num;
		printf("%04d-%02d-%02d", year, month, day);
	}
	return 0;
}