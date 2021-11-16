#include<iostream>
#include<string>
using namespace std;

void main()
{
	string s1 = "abc";
	string s2 = "xyz";
	s1.erase(s1.begin());
	cout << s1 << endl;

}