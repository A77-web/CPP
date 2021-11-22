#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int firstUniqChar(string s)
	{
		int j;
		for (int i = 0; i < s.size(); ++i)
		{
			for (j = 0; j < s.size(); ++j)
			{
				if (j==i)
					continue;
				if (s[j] == s[i])
					break;
			}
			if (j >= s.size())
				return s[i];
		}
		return -1;
	}
};
void main()
{
	Solution a;
	char ret = a.firstUniqChar("asdfasdfo");
	cout << ret << endl;
}