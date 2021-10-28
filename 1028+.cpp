#include<iostream>
using namespace std;
template<typename T>
T Add(const T& left, const T& light)
{
	return left + light;
}
int main()
{
	int a = 10;
	int b = 20;
	double a1 = 10.0;
	double b1 = 20.0;
	cout<<Add(a, b)<<endl;
	cout<<Add(a1, b1)<<endl;
	cout<<Add(a, (int)b1)<<endl;
	return 0;
}