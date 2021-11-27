#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	string reverseStr(string s, int k)
	{
		int n = s.length();
			for (int i = 0; i < n;i+=2*k)
			{
				reverse(s.begin() + i, s.begin() + min(i + k, n));
			}
			return s;
	}
};
void main()
{
	Solution a;
	string str = a.reverseStr("abcdefg", 2);
	cout << str;
	

}