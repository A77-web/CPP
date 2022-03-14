
#include <iostream>
#include <vector>
using namespace std;

/*不断循环，用剩余空瓶数除以3，将结果加起来
 *	如果剩余两个空瓶，则可兑换数+1，循环结束
 *	如果剩余1个空瓶，直接结束循环
 *	最多10组测试用例，以0结束，所以用大小为10的vector接收，直到接收值为0结束*/
int GetNum(int n)
{
	int ret = 0; //可兑换数初始为0
	while (n > 1)
	{
		if (n == 2)
		{
			ret += 1;
			break;
		}
		else
			ret += n / 3;
		n = n / 3 + n % 3; //更新剩余空瓶数
	}
	return ret;
}

int main()
{
	int n, i = 0;
	vector<int> a(10);
	while (cin >> n)
	{
		if (n == 0)
			break;
		a[i++] = n;
	}
	for (int j = 0; j < i; ++j)
	{
		cout << GetNum(a[j])<<endl;
	}
	return 0;
}

