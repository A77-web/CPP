#include<iostream>
using namespace std;
#include<list>
void main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(ar[0]);
	//list<int> mylist;  //��ͷ����˫��ѭ������
	//list<int> mylist(10, 5);
	list<int> mylist(ar, ar + n);
	for (const auto& e : mylist)
		cout << e << " ";
	cout << endl;

	list<int> youlist = mylist;
	for (const auto& e : youlist)
		cout << e << " ";
	cout << endl;
}