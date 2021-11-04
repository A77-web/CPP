#include<iostream>
#include<list>
using namespace std;
void main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	list<int>mylist(arr, arr + n);
	for (const auto& t : mylist)
		cout << t << " ";
	cout << endl;
	list<int>youlist = mylist;
	for (const auto& t : youlist)
		cout << t << " ";
	cout << endl;
}