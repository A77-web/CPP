#include<iostream>
#include<string>
using namespace std;
//hash·¨
class Solution {
public:
	int firstUniqChar(string s)
	{
		//0~255 hash[0]~hash[255]
		int hash[256] = { 0 };
		for (int i = 0; i < s.size(); ++i)
		
			hash[s[i]]++;
		
		for (int i = 0; i < s.size(); ++i)
		{
			if (hash[s[i]] == 1)
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