#include<iostream>
#include<string>
using namespace std;

void main()
{
	string s1 = "abcxyzab";
	int index = s1.find_last_not_of("yxza");
	cout << index << endl;
}