#include<iostream>
#include<list>
using namespace std;
void main()
{
	int ar[] = {6,5,8,3,1,4,2,7,9 };
	int n = sizeof(ar) / sizeof(ar[0]);
	list<int>lt4(ar, ar + n);
	for (const auto& e : lt4)
		cout << e << "-->";
	cout << "Over." << endl;

	lt4.sort();

	for (const auto& e : lt4)
		cout << e << "-->";
	cout << "Over." << endl;
}