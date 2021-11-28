#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	int AddItem(int a, int b, int& sign)
	{
		int sum = a + b + sign;
		if (sum >= 10)
		{
			sum -= 10;
			sign = 1;
		}
		else
			sign = 0;
		return sum;
	}
	string AddStrings(string num1, string num2)
	{
		reverse(num1.begin(), num1.end());//123  321
		reverse(num2.begin(), num2.end());//456  654
		int i, j;
		i = j = 0;
		int sign = 0;//进位初始化
		string result;
		int sum = 0;
		while (i < num1.size() && j < num2.size())
		{
			sum = AddItem(num1[i] - '0', num2[j] - '0', sign);
			result.push_back(sum + '0');
			i++;
			j++;
		}
		while (i < num1.size())
		{
			sum = AddItem(num1[i] - '0', 0, sign);
			result.push_back(sum + '0');
			i++;
		}

		while (j < num2.size())
		{
			sum = AddItem(0, num2[j] - '0', sign);
			result.push_back(sum + '0');
			j++;
		}
		if (sign > 0)
			result.push_back(sign + '0');
		reverse(result.begin(), result.end());
		return result;

	}
};
void main()
{
	Solution a;
	string ret=a.AddStrings("12341", "7987978");
	cout << ret << endl;
}