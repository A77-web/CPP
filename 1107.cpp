#include<iostream>
#include<list>
#include<functional>
using namespace std;

void main()
{
	int ar[] = { 1,2,3,4,5 };
	int n1 = sizeof(ar) / sizeof(ar[0]);
	int br[] = { 10,20,30,40,50 };
	int n2 = sizeof(ar) / sizeof(ar[0]);

	list<int> lt4(ar, ar + n1);
	for (const auto& e : lt4)
		cout << e << "-->";
	cout << "Over." << endl;

	list<int> lt5(br, br + n2);
	for (const auto& e : lt5)
		cout << e << "-->";
	cout << "Over." << endl;

	list<int>::iterator pos = find(lt4.begin(), lt4.end(), 3);
	//lt4.splice(pos, lt5);
	list<int>::iterator start = find(lt5.begin(), lt5.end(), 30);
	//lt4.splice(pos,  lt5, start);
	lt4.splice(pos, lt5, start, lt5.end());

	for (const auto& e : lt4)
		cout << e << "-->";
	cout << "Over." << endl;

	for (const auto& e : lt5)
		cout << e << "-->";
	cout << "Over." << endl;

}
