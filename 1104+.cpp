#include<iostream>
#include<list>
using namespace std;
void main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(ar[0]);
	list<int> mylist(ar, ar + n);

	for (const auto& e : mylist)
		cout << e << " ";
	cout << endl;
	list<int>::iterator it = mylist.begin();
	while (it != mylist.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << endl;
	list<int>::reverse_iterator rit = mylist.rbegin();
	while (rit != mylist.rend())
	{
		cout << *rit << endl;
		++rit;
	}
	cout << endl;
}
