#include<iostream>
#include<string>
using namespace std;
void main()
{
	string s = "abcxyzab";
	int index = s.find_first_of("yxza");
	cout << index << endl;
}