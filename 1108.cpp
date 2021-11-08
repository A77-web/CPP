#include<iostream>
#include<list>
using namespace std;
void main()
{
	int ar[] = { 1,1,2,2,3,3,4,4,5,5,5,5,5,7,6,4 };
	int n = sizeof(ar) / sizeof(ar[0]);
	list<int>lt4(ar, ar + n);
	for (const auto& e : lt4)
		cout << e << "-->";
	cout << "Over." << endl;

	lt4.unique();
	for (const auto& e : lt4)
		cout << e << "-->";
	cout << "Over." << endl;
}