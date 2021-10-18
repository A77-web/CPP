#include<iostream>
#include<Windows.h>
using namespace std;
 
int main()
{
	int max(int a, int b, int c);
	int max(int a, int b);
	int a = 10;
	int b = 20;
	int c = 30;
 
	cout << max(a, b, c) << endl;
	cout << max(a, b) << endl;
	system("pause");
	return 0;
}
 
 
int max(int a, int b, int c)
{
	if (b > a)
		a = b;
	if (c > a)
		a = c;
	return a;
 
}
 
int max(int a, int b)
{
 
	return (a > b) ? a : b;
}
