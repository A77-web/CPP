#include<iostream>
#include<string>
using namespace std;

void main()
{
	string s1 = "abc";
	string s2 = "xyz";
	cout << s1 << endl;
	cout << s2 << endl;

	s1.swap(s2);
	cout << s1 << endl;
	cout << s2 << endl;

}