#include<iostream>
using namespace std;
//专门处理int的加法函数
int Add(int left, int right)
{
	return left + right;
}
//通用加法函数
template<class T1,class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}
void main()
{
	cout<<Add(1, 2)<<endl;
	cout<<Add(1, 2.0)<<endl;
}
