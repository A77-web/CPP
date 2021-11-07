#include<iostream>
#include<list>
using namespace std;
void main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(ar[0]);
	list<int>lt4(ar, ar + n);
	for (const auto& e : lt4)
		cout << e << "-->";
	cout << "Over" << endl;

	lt4.reverse();
	for (const auto& e : lt4)
		cout << e << "-->";
	cout << "Over" << endl;
}