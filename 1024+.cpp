#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
bool isRun(int year)  //�ж��ǲ������� 
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}

int main() {
	int date[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };   //�������29�죬ƽ��28�� 
	int year, num;
	while (scanf("%d %d", &year, &num) != EOF)
	{
		if (isRun(year))
			date[1] = 29;
		else
			date[1] = 28;
		int i, sum = 0;//sumΪ�� 
		for (i = 0; i < 12; i++)
		{
			sum += date[i];
			if (sum >= num)
			{
				break;
			}
		}
		printf("%04d-%02d-%02d\n", year, i + 1, num - (sum - date[i]));  //Ҫע��%04d
	}
	return 0;
}
