#include<iostream>
#include<list>
using namespace std;
void main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9 };
	int n = sizeof(ar) / sizeof(ar[0]);
	list<int>lt1(ar, ar + n);
	for (const auto& e : lt1)
		cout << e << "-->";
	cout << "over" << endl;

	lt1.clear();

	for (const auto& e :  lt1)
		cout << e << "-->";
	cout << "Over" << endl;
}