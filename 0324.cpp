#include<iostream>
#include<string>
using namespace std;
int main()
{
	
	string str;
	//用字符串接收，防止数字过大
	while (cin >> str)
	{
		int num = 0;
		for (int i = 0; i < str.size(); i++)
		{
			num += str[i] -'0';
		}
		int sum = 0;
		while (num)
		{
			sum += num % 10;
			num = num / 10;
			if (num == 0 && sum / 10 != 0)
			{
				num=sum  ;
				sum = 0;
			}
		}
		cout << sum << endl;
	}
}