#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	void MulItem(string& num, int s, string &tmp)
	{
		int sign = 0;
		for (int i = 0; i < num.size(); ++i)
		{
			int mul = (num[i] - '0') * s + sign;
			if (mul > 10)
			{
				sign = mul / 10;
				mul %= 10;
			}
			else
				sign = 0;
			tmp.push_back(mul + '0');
		}
		if (sign > 0)
			tmp.push_back(sign + '0');
	}
	int AddItem(int a, int b, int& sign)
	{
		int sum = a + b + sign;
		if (sum > 10)
		{
			sum -= 10;
			sign = 1;
		}
		else
			sign = 0;
		return sum;
	}
	void AddMove(string& num, string& tmp, int k)
	{
		int i = k;
		int j = 0;
		int sign = 0;
		while (i < num.size() && j < tmp.size())
		{
			num[i] = AddItem(num[i] - '0', tmp[j] - '0', sign) + '0';
			i++;
			j++;
		}
		while (i < num.size())
		{
			num[i] = AddItem(num[i] - '0', 0, sign) + '0';
			i++;
		}

		while (j < tmp.size())
		{
			int sum = AddItem(0, tmp[j] - '0', sign);
			num.push_back(sum + '0');
			j++;
		}
		if (sign > 0)
			num.push_back(sign+'0');
	}
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")
			return string("0");
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		string tmp, result;
		for (int i = 0; i < num2.size(); i++)
		{
			MulItem(num1, num2[i] + '0', tmp);
			AddMove(result, tmp, i);
			tmp.clear();
		}
		reverse(result.begin(), result.end());
		return result;

	}
};