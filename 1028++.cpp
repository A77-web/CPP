#include<iostream>
using namespace std;
//ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
	return left + right;
}
//ͨ�üӷ�����
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
