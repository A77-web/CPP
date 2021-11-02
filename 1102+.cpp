#include<iostream>
using namespace std;
void fun(int a, int b=1, int c=2);

void main()
{
	fun(10);
}

void fun(int a, int b, int c)
{
	int result = a + b + c;
	cout<<"result = "<<result<<endl;
}
