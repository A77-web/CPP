#include<iostream>
using namespace std;
template<typename Type>
void Swap(Type& a, Type& b)
{
	cout << typeid(Type).name() << endl;
	Type tmp = a;
	a = b;
	b = tmp;
}
void main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	char ch1 = 'A';
	char ch2 = 'B';
	Swap(ch1, ch2);
	
}